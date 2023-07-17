/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 09:32:18 by aqueiroz          #+#    #+#             */
/*   Updated: 2023/07/08 15:09:02 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <readline/history.h>
#include <readline/readline.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <dirent.h>
#include <limits.h>
#include <errno.h>
#include <fcntl.h>

#define TOKEN_DELIMITERS " \t\r\n\a"
#define BUFFER_SIZE 1024

int interactive_mode = 1;
extern char** environ;

int last_pipeline_status = 0; // Variável global para armazenar o status do pipeline mais recente

void cleanup() {
    pid_t result;
    do {
        result = waitpid(-1, NULL, WNOHANG);
    } while (result > 0 || (result == -1 && errno == EINTR));
}

char* read_line() {
    char* line = readline("minishell$ ");
    if (line && *line) {
        add_history(line);
    }
    return line;
}

char* expand_variable(char* command) {
    if (strcmp(command, "$?") == 0) {
        char* expanded = malloc(sizeof(char) * BUFFER_SIZE);
        snprintf(expanded, BUFFER_SIZE, "%d", last_pipeline_status);
        return expanded;
    }
    return command;
}

char** tokenize_line(char* line) {
    int buffer_size = BUFFER_SIZE;
    int position = 0;
    char** tokens = malloc(buffer_size * sizeof(char*));
    char* token;

    if (!tokens) {
        fprintf(stderr, "Allocation error\n");
        exit(EXIT_FAILURE);
    }

    token = strtok(line, TOKEN_DELIMITERS);
    while (token != NULL) {
        tokens[position] = token;
        position++;

        if (position >= buffer_size) {
            buffer_size += BUFFER_SIZE;
            tokens = realloc(tokens, buffer_size * sizeof(char*));
            if (!tokens) {
                fprintf(stderr, "Allocation error\n");
                exit(EXIT_FAILURE);
            }
        }

        token = strtok(NULL, TOKEN_DELIMITERS);
    }
    tokens[position] = NULL;

    // Expandir variáveis nos tokens
    for (int i = 0; tokens[i] != NULL; i++) {
        tokens[i] = expand_variable(tokens[i]);
    }

    return tokens;
}

void execute_echo(char* args[]) {
    int i = 1;
    int no_newline = 0;

    if (args[1] != NULL && strcmp(args[1], "-n") == 0) {
        no_newline = 1;
        i = 2;
    }

    int total_length = 0;
    for (int j = i; args[j] != NULL; j++) {
        total_length += strlen(args[j]) + 1;
    }

    char* result = (char*)malloc(total_length * sizeof(char));
    if (result == NULL) {
        printf("Memory allocation error.\n");
        return;
    }

    int pos = 0;
    for (int j = i; args[j] != NULL; j++) {
        int len = strlen(args[j]);
        char temp[len + 1];
        int temp_pos = 0;

        int in_single_quotes = 0;
        int in_double_quotes = 0;

        for (int k = 0; k < len; k++) {
            if (args[j][k] == '\'') {
                in_single_quotes = !in_single_quotes;
            } else if (args[j][k] == '\"') {
                in_double_quotes = !in_double_quotes;
            } else {
                temp[temp_pos++] = args[j][k];
            }
        }

        temp[temp_pos] = '\0';

        if (pos > 0) {
            result[pos++] = ' ';
        }

        strcpy(&result[pos], temp);
        pos += strlen(temp);
    }

    printf("%s", result);
    free(result);

    if (!no_newline)
        printf("\n");
}


void execute_cd(char* args[]) {
    char* path = args[1];

    if (path == NULL) {
        // No argument provided, change to home directory
        char* home = getenv("HOME");
        if (home == NULL) {
            perror("cd");
            return;
        }
        path = home;
    }

    if (chdir(path) != 0) {
        perror("cd");
    }
}

void execute_pwd() {
    char cwd[PATH_MAX];
    if (getcwd(cwd, sizeof(cwd)) != NULL) {
        printf("%s\n", cwd);
    } else {
        fprintf(stderr, "pwd: %s\n", strerror(errno));
    }
}

void execute_export(char* args[]) {
    char* name = args[1];
    if (name == NULL) {
        // Print all environment variables
        extern char** environ;
        for (char** env = environ; *env != NULL; env++) {
            printf("%s\n", *env);
        }
    } else {
        if (setenv(name, "", 1) != 0) {
            fprintf(stderr, "export: %s: %s\n", name, strerror(errno));
        }
    }
}

void execute_unset(char* args[]) {
    char* name = args[1];
    if (name == NULL) {
        fprintf(stderr, "unset: missing argument\n");
        return;
    }

    if (unsetenv(name) != 0) {
        fprintf(stderr, "unset: %s: %s\n", name, strerror(errno));
    }
}

void execute_env() {
    extern char** environ;
    for (char** env = environ; *env != NULL; env++) {
        printf("%s\n", *env);
    }
}

void execute_ls() {
    struct dirent** entries;
    struct dirent* entry;
    int num_entries;
    int i;

    num_entries = scandir(".", &entries, NULL, alphasort);
    if (num_entries == -1) {
        perror("ls");
        return;
    }

    i = 0;
    while (i < num_entries) {
        entry = entries[i];
        printf("%s ", entry->d_name);
        free(entries[i]);
        i++;
    }
    printf("\n");

    free(entries);
}

void execute_exit() {
    exit(0);
}

void execute_command(char* command[], int input_fd, int output_fd) {
    if (strcmp(command[0], "echo") == 0) {
        execute_echo(command);
        return;
    } else if (strcmp(command[0], "cd") == 0) {
        execute_cd(command);
        return;
    } else if (strcmp(command[0], "pwd") == 0) {
        execute_pwd();
        return;
    } else if (strcmp(command[0], "export") == 0) {
        execute_export(command);
        return;
    } else if (strcmp(command[0], "unset") == 0) {
        execute_unset(command);
        return;
    } else if (strcmp(command[0], "env") == 0) {
        execute_env();
        return;
    } else if (strcmp(command[0], "exit") == 0) {
        execute_exit();
        return;
    } else if (strcmp(command[0], "ls") == 0) {
        execute_ls();
        return;
    }

    pid_t pid = fork();
    if (pid == 0) {
        // Child process
        if (input_fd != STDIN_FILENO) {
            dup2(input_fd, STDIN_FILENO);
            close(input_fd);
        }

        if (output_fd != STDOUT_FILENO) {
            dup2(output_fd, STDOUT_FILENO);
            close(output_fd);
        }

        execve(command[0], command, environ);
        perror(command[0]);
        exit(EXIT_FAILURE);
    } else if (pid < 0) {
        // Error forking
        perror("Fork error");
    } else {
        // Parent process
        waitpid(pid, &last_pipeline_status, 0); // Armazena o status de saída do pipeline filho
    }
}

void execute_pipeline(char* commands[][BUFFER_SIZE], int num_commands) {
    int input_fd = STDIN_FILENO;
    int fd[2];
    int i;

    for (i = 0; i < num_commands - 1; i++) {
        pipe(fd);
        execute_command(commands[i], input_fd, fd[1]);
        close(fd[1]);
        input_fd = fd[0];
    }

    if (input_fd != STDIN_FILENO) {
        dup2(input_fd, STDIN_FILENO);
        close(input_fd);
    }

    execute_command(commands[i], input_fd, STDOUT_FILENO);
}

void handle_sigint(int signum) {
    if (interactive_mode) {
        write(STDOUT_FILENO, "\nminishell$ ", 12);
        fflush(stdout);
    } else {
        exit(0);
    }
}

void handle_eof(int signum) {
    if (!interactive_mode) {
        write(STDOUT_FILENO, "exit\n", 5);  // Print "exit" command
        fflush(stdout);
        cleanup(); // Free memory and terminate pending processes
        exit(EXIT_SUCCESS);
    } else {
        cleanup(); // Free memory and terminate pending processes
        exit(EXIT_SUCCESS);
    }
}

int main() {
    char* line;
    char** commands;
    int num_commands;
    int i;

    signal(SIGINT, handle_sigint);
    signal(SIGQUIT, SIG_IGN);  // Ignore SIGQUIT (Ctrl-\)

    if (!isatty(STDIN_FILENO)) {
        interactive_mode = 0;
    }

    while (1) {
        line = read_line();
        if (line == NULL) {
            printf("exit\n");  // Print "exit" command
            fflush(stdout);
            cleanup();  // Free memory and terminate pending processes
            exit(EXIT_SUCCESS);
        }

        if (strspn(line, " \t\r\n\a") != strlen(line)) {
            commands = tokenize_line(line);

            num_commands = 0;
            for (i = 0; commands[i] != NULL; i++) {
                if (strcmp(commands[i], "|") == 0) {
                    num_commands++;
                    commands[i] = NULL;
                }
            }
            num_commands++;

            char* pipeline[num_commands][BUFFER_SIZE];
            int command_index = 0;
            int arg_index = 0;

            for (i = 0; commands[i] != NULL; i++) {
                if (strcmp(commands[i], "|") == 0) {
                    pipeline[command_index][arg_index] = NULL;
                    command_index++;
                    arg_index = 0;
                } else {
                    pipeline[command_index][arg_index] = commands[i];
                    arg_index++;
                }
            }
            pipeline[command_index][arg_index] = NULL;

            execute_pipeline(pipeline, num_commands);

            free(line);
            free(commands);
        } else {
            free(line);
        }
    }

    return 0;
}
