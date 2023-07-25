/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 09:32:18 by aqueiroz          #+#    #+#             */
/*   Updated: 2023/07/25 08:52:24 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <signal.h>

extern char **environ;
volatile sig_atomic_t running_command = 0;
volatile sig_atomic_t exit_shell = 0;

void sigint_handler(int sig)
{
    if (running_command)
    {
        // Terminate the running command on SIGINT (Ctrl-C)
        running_command = 0;
        printf("\nminishell$ ");
        fflush(stdout);
    }
    else
    {
        // Ignore SIGINT (Ctrl-C) if no running command
    }
}

void sigquit_handler(int sig)
{
    // Ignore SIGQUIT (Ctrl-\) in interactive mode
}

void sigtstp_handler(int sig)
{
    // Ignore SIGTSTP (Ctrl-Z) in interactive mode
}

void sigterm_handler(int sig)
{
    exit_shell = 1;
}

char *read_line(void)
{
    char *line;

    line = readline("minishell$ ");
    if (*line)
        add_history(line);
    return (line);
}

int is_special_character(char c)
{
    // Add any additional special characters you want to handle here
    return (c == '|' || c == '&' || c == '<' || c == '>' || c == '$');
}

char **tokenize(char *input)
{
    int buffer_size = 64;
    char **tokens = (char **)malloc(buffer_size * sizeof(char *));
    if (!tokens)
    {
        fprintf(stderr, "Memory allocation error\n");
        exit(EXIT_FAILURE);
    }

    char *token;
    char *delimiters = " \t\r\n\a";
    int token_index = 0;
    int in_single_quotes = 0;
    int in_double_quotes = 0;

    token = strtok(input, delimiters);
    while (token != NULL)
{
    // Check for unclosed double quotes
    int double_quote_count = 0;
    for (int i = 0; i < strlen(token); i++)
    {
        if (token[i] == '"')
            double_quote_count++;
    }

    if (double_quote_count % 2 != 0 && !in_single_quotes) // Check only if not already in single quotes
    {
        fprintf(stderr, "Unclosed double quotes\n");
        free(tokens);
        return NULL;
    }

    // Check for unclosed single quotes
    int single_quote_count = 0;
    for (int i = 0; i < strlen(token); i++)
    {
        if (token[i] == '\'')
            single_quote_count++;
    }

    if (single_quote_count % 2 != 0 && !in_double_quotes) // Check only if not already in double quotes
    {
        fprintf(stderr, "Unclosed single quotes\n");
        free(tokens);
        return NULL;
    }

    // Check for single quotes and handle meta-characters inside them
    if (token[0] == '\'')
    {
        in_single_quotes = 1;
        memmove(token, token + 1, strlen(token)); // Remove the starting single quote
    }

    if (in_single_quotes)
    {
        if (token[strlen(token) - 1] == '\'')
        {
            in_single_quotes = 0;
            token[strlen(token) - 1] = '\0'; // Remove the ending single quote
        }
    }

    // Check for double quotes and handle meta-characters inside them (except $)
    if (token[0] == '"')
    {
        in_double_quotes = 1;
        memmove(token, token + 1, strlen(token)); // Remove the starting double quote
    }

    if (in_double_quotes)
    {
        for (int i = 0; i < strlen(token); i++)
        {
            if (token[i] == '\\' && token[i + 1] != '$')
            {
                // Remove the backslash unless it's before a dollar sign
                memmove(token + i, token + i + 1, strlen(token) - i);
            }
        }

        if (token[strlen(token) - 1] == '"')
        {
            in_double_quotes = 0;
            token[strlen(token) - 1] = '\0'; // Remove the ending double quote
        }
    }

    tokens[token_index] = token;
    token_index++;

    // Check if we need to allocate more memory for tokens
    if (token_index >= buffer_size)
    {
        buffer_size *= 2;
        tokens = realloc(tokens, buffer_size * sizeof(char *));
        if (!tokens)
        {
            fprintf(stderr, "Memory allocation error\n");
            exit(EXIT_FAILURE);
        }
    }

    token = strtok(NULL, delimiters);
}

    tokens[token_index] = NULL;
    return tokens;
}

char *expand_environment_variable(char *variable)
{
    char *value = getenv(variable + 1); // Skip the leading $

    if (value == NULL)
    {
        fprintf(stderr, "Environment variable not found: %s\n", variable);
        return variable; // Return the original variable if not found
    }

    return value;
}

void expand_environment_variables(char **args)
{
    for (int i = 0; args[i] != NULL; i++)
    {
        if (args[i][0] == '$')
        {
            char *expanded_variable = expand_environment_variable(args[i]);
            free(args[i]);
            args[i] = strdup(expanded_variable);
        }
    }
}
int handle_redirections(char **args)
{
    int i, input_fd, output_fd;
    char *input_file = NULL;
    char *output_file = NULL;
    int here_document = 0;

    int append_fd = -1; // Declare append_fd outside the loop
    int pipefds[2];    // Declare pipefds array here

    // Look for the redirection symbols and process them accordingly
    for (i = 0; args[i] != NULL; i++)
    {
        if (strcmp(args[i], "<") == 0)
        {
            input_file = args[i + 1];
            args[i] = NULL;
            break;
        }
        else if (strcmp(args[i], ">") == 0)
        {
            output_file = args[i + 1];
            args[i] = NULL;
            break;
        }
        else if (strcmp(args[i], ">>") == 0)
        {
            output_file = args[i + 1];
            append_fd = open(output_file, O_WRONLY | O_CREAT | O_APPEND, 0644);
            args[i] = NULL;
            break;
        }
        else if (strcmp(args[i], "<<") == 0)
        {
            here_document = 1;
            args[i] = NULL;
            break;
        }
    }

    // Perform the input redirection
    if (input_file != NULL)
    {
        input_fd = open(input_file, O_RDONLY);
        if (input_fd == -1)
        {
            perror("Input redirection error");
            return 0;
        }
        dup2(input_fd, STDIN_FILENO);
        close(input_fd);
    }

    // Perform the output redirection
    if (output_file != NULL)
    {
        if (append_fd == -1) // If not using append mode
            output_fd = open(output_file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
        else
            output_fd = append_fd;
        if (output_fd == -1)
        {
            perror("Output redirection error");
            return 0;
        }
        dup2(output_fd, STDOUT_FILENO);
        close(output_fd);
    }

    // Handle here-document input redirection
    if (here_document)
    {
        char *delimiter = args[i + 1];
        char *line = NULL;
        size_t line_buf_size = 0;

        if (pipe(pipefds) == -1)
        {
            perror("Pipe creation failed");
            exit(EXIT_FAILURE);
        }

        while (1)
        {
            ssize_t read_bytes = getline(&line, &line_buf_size, stdin);
            if (read_bytes == -1 || strcmp(line, delimiter) == 0)
            {
                break;
            }
            // Write to the input of the current command
            write(pipefds[1], line, read_bytes);
        }

        free(line);
        close(pipefds[1]); // Close the write end of the pipe for the here-document
    }

    return 1;
}

int execute_pipeline(char **args)
{
    int i, num_commands = 0;
    int pipefds[2]; // File descriptors for the pipe
    int prev_pipe = 0; // Keeps track of the previous pipe output
    char **command_args[100]; // Max of 100 commands in the pipeline

    // Divide the commands into separate arrays and handle pipes
    for (i = 0; args[i] != NULL; i++)
    {
        if (strcmp(args[i], "|") == 0)
        {
            args[i] = NULL; // Null terminate the current command
            command_args[num_commands++] = &args[prev_pipe]; // Store the command in the array
            prev_pipe = i + 1;
        }
    }

    args[i] = NULL; // Null terminate the last command
    command_args[num_commands++] = &args[prev_pipe]; // Store the last command in the array

    int pid;
    for (i = 0; i < num_commands; i++)
    {
        if (i < num_commands - 1) // If not the last command, create a pipe
        {
            if (pipe(pipefds) == -1)
            {
                perror("Pipe creation failed");
                exit(EXIT_FAILURE);
            }
        }

        pid = fork();
        if (pid == 0) // Child process
        {
            if (i > 0) // Not the first command, read from the previous pipe
            {
                if (dup2(prev_pipe, STDIN_FILENO) == -1)
                {
                    perror("Pipe input redirection failed");
                    exit(EXIT_FAILURE);
                }
                close(prev_pipe);
            }

            if (i < num_commands - 1) // Not the last command, write to the current pipe
            {
                if (dup2(pipefds[1], STDOUT_FILENO) == -1)
                {
                    perror("Pipe output redirection failed");
                    exit(EXIT_FAILURE);
                }
                close(pipefds[1]);
            }

            if (execvp(command_args[i][0], command_args[i]) == -1)
            {
                perror("Command execution failed");
                exit(EXIT_FAILURE);
            }
        }
        else if (pid > 0) // Parent process
        {
            if (i > 0)
            {
                close(prev_pipe);
            }

            if (i < num_commands - 1)
            {
                close(pipefds[1]);
                prev_pipe = pipefds[0]; // Save the read end of the current pipe for the next command
            }
        }
        else // Forking failed
        {
            perror("Forking failed");
            exit(EXIT_FAILURE);
        }
    }

    // Wait for all child processes to finish
    for (i = 0; i < num_commands; i++)
    {
        wait(NULL);
    }

    return 1;
}

// Built-in function: echo
int shell_echo(char **args)
{
    int i = 1;
    int suppress_newline = 0;

    if (args[i] != NULL && strcmp(args[i], "-n") == 0)
    {
        suppress_newline = 1;
        i++;
    }

    while (args[i] != NULL)
    {
        printf("%s", args[i]);
        i++;
        if (args[i] != NULL)
            printf(" ");
    }

    if (!suppress_newline)
        printf("\n");

    return 1;
}

// Built-in function: cd
int shell_cd(char **args)
{
    if (args[1] == NULL)
    {
        fprintf(stderr, "cd: expected argument to \"cd\"\n");
    }
    else
    {
        if (chdir(args[1]) != 0)
        {
            perror("cd");
        }
    }
    return 1;
}

// Built-in function: pwd
int shell_pwd(char **args)
{
    char cwd[1024];
    if (getcwd(cwd, sizeof(cwd)) != NULL)
    {
        printf("%s\n", cwd);
    }
    else
    {
        perror("pwd");
    }
    return 1;
}

// Built-in function: export
int shell_export(char **args)
{
    int i = 1;
    while (args[i] != NULL)
    {
        putenv(args[i]);
        i++;
    }
    return 1;
}

// Built-in function: unset
int shell_unset(char **args)
{
    int i = 1;
    while (args[i] != NULL)
    {
        unsetenv(args[i]);
        i++;
    }
    return 1;
}

// Built-in function: env
int shell_env(char **args)
{
    char **env = environ;
    while (*env != NULL)
    {
        printf("%s\n", *env);
        env++;
    }
    return 1;
}

// Built-in function: exit
int shell_exit(char **args)
{
    exit_shell = 1;
    return 1;
}

// Built-in functions array and their corresponding names
char *builtin_str[] = {
    "echo",
    "cd",
    "pwd",
    "export",
    "unset",
    "env",
    "exit"};

int (*builtin_func[])(char **) = {
    &shell_echo,
    &shell_cd,
    &shell_pwd,
    &shell_export,
    &shell_unset,
    &shell_env,
    &shell_exit};

int num_builtins()
{
    return sizeof(builtin_str) / sizeof(char *);
}

int is_builtin(char *cmd)
{
    for (int i = 0; i < num_builtins(); i++)
    {
        if (strcmp(cmd, builtin_str[i]) == 0)
            return i;
    }
    return -1;
}

int execute_command(char **args)
{
    int builtin_index = is_builtin(args[0]);
    if (builtin_index >= 0)
        return (*builtin_func[builtin_index])(args);

    // Handle external commands
    // ... (code for executing external commands goes here)
    // For now, we'll just print a message indicating that the command is not a built-in
    printf("Command not found: %s\n", args[0]);
    return 1;
}

int main()
{
    char *input;

    // Set up signal handlers for SIGINT, SIGQUIT, SIGTSTP, and SIGTERM
    struct sigaction sa_int, sa_quit, sa_tstp, sa_term;
    sa_int.sa_handler = sigint_handler;
    sa_quit.sa_handler = sigquit_handler;
    sa_tstp.sa_handler = sigtstp_handler;
    sa_term.sa_handler = sigterm_handler;
    sigemptyset(&sa_int.sa_mask);
    sigemptyset(&sa_quit.sa_mask);
    sigemptyset(&sa_tstp.sa_mask);
    sigemptyset(&sa_term.sa_mask);
    sa_int.sa_flags = 0;
    sa_quit.sa_flags = 0;
    sa_tstp.sa_flags = 0;
    sa_term.sa_flags = 0;
    sigaction(SIGINT, &sa_int, NULL);
    sigaction(SIGQUIT, &sa_quit, NULL);
    sigaction(SIGTSTP, &sa_tstp, NULL);
    sigaction(SIGTERM, &sa_term, NULL);

    while (!exit_shell)
    {
        input = read_line();
        // parser
        // tokenrizador
        // execute commands
        char **args = tokenize(input);
        if (args != NULL)
        {
            expand_environment_variables(args); // Handle environment variable expansion
            int result = handle_redirections(args);
            if (result)
            {
                running_command = 1;
                execute_pipeline(args);
                running_command = 0;
            }
            free(args);
        }
        free(input);
    }
    rl_clear_history();
    return (0);
}
