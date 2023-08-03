/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 09:32:18 by aqueiroz          #+#    #+#             */
/*   Updated: 2023/08/03 10:13:17 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
/*int	launch_executable(cha r *command, char **environ)
{
// Check if the command contains an absolutrelative path
	if (strchr(command, '/'))
// Execute using the provided path
		return execve(command, (char *const[]){command, (char *)NULL}, environ);

// If not an absolute or relative path, search for the executable in PATH directories
	char	*path_env;

	path_env = getenv("PATH");
	if (path_env == NULL)
	{
		printf("Error: PATH environment variable is not set.\n");
		return (-1);
	}

    char *path = strtok(path_env, ":");
    while (path != NULL) {
        char *executable = (char *)malloc(strlen(path) + strlen(command) + 2); // +2 for '/' and '\0'
        if (executable == NULL) {
            printf("Error: Memory allocation failed.\n");
            return -1;
        }
        sprintf(executable, "%s/%s", path, command);
        execve(executable, (char *const[]){executable, (char *)NULL}, environ);
        free(executable);
        path = strtok(NULL, ":");
    }

    // If the command is not found in any of the PATH directories, print an error
    printf("Command not found: %s\n", command);
    return -1;
}

void handle_command(char *line, char **environ) {
    // Tokenize the line to get the command and arguments
    char *token = strtok(line, " \t\n");
    if (token == NULL) {
        // Empty line or only spaces
        return;
    }

    // Check if it's a built-in command
    if (strcmp(token, "exit") == 0) {
        // Handle "exit" command
        write(1, "exit\n", 5);
        clean_up();
        exit(EXIT_SUCCESS);
    }
    // Add other built-in commands here

    // Launch the executable based on the user input
    int status = launch_executable(token, environ);
    if (status == -1) {
        // Handle errors or unsupported commands
    }
} */

t_config	*get_data(void)
{
	static t_config	data;

	return (&data);
}

int	main(void)
{
	extern char	**environ;
	char		*line;
	t_config	*config;

	config = get_data();

	config->env = environ;
	config->interactive_mode = 1;

	init_shell(environ);
	if (!isatty(STDIN_FILENO))
		config->interactive_mode = 0;
	while (1)
	{
		line = read_line();
		if (line == NULL)
			continue ;
		free(line);
	}
	return (0);
}
