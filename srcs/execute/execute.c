/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 18:49:30 by fsuomins          #+#    #+#             */
/*   Updated: 2023/08/17 00:50:00 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

#define MAX_CHILD_PIDS 100
void execute_cmd_list(t_config *data)
{
    pid_t pid;
    char **args;
    int status;
    t_cmd *current_token = data->tokens;
    char *path;
    char *path_env;
    char *token;
    char *full_path;

    while (current_token != NULL)
    {
		pid_t pid = fork();
		if (pid < 0)
        {
            perror("fork");
            exit(EXIT_FAILURE);
        }
		else if (pid == 0) {
			// if (input_fd != STDIN_FILENO) {
			// 	dup2(input_fd, STDIN_FILENO);
			// 	close(input_fd);
			// }

			// if (output_fd != STDOUT_FILENO) {
			// 	dup2(output_fd, STDOUT_FILENO);
			// 	close(output_fd);
			// }
			path_env = getenv("PATH");
            token = strtok(path_env, ":");
            while (token != NULL)
            {
                full_path = ft_strjoin(token, "/");
                full_path = ft_strjoin(full_path, current_token->cmd);
                if (access(full_path, X_OK) == 0)
                {
                    args = malloc(sizeof(char *) * 3);
                    args[0] = current_token->cmd;
                    args[1] = current_token->argv;
                    args[2] = NULL;
                    execve(full_path, args, data->env);
                    break;
                }
                token = strtok(NULL, ":");
            }
            if (token == NULL)
            {
                printf("command not found\n");
                exit(EXIT_FAILURE);
            }
			perror(current_token->cmd);
			exit(EXIT_FAILURE);
		} else {
			waitpid(pid, &data->exit_code, 0);
		}
        current_token = current_token->next;
    }
}

void close_fds(pid_t *child_pids, int num_pids)
{
    for (int i = 0; i < num_pids; i++)
    {
        close(child_pids[i]);
    }
}

void kill_child_pids(pid_t *child_pids, int num_pids)
{
    for (int i = 0; i < num_pids; i++)
    {
        kill(child_pids[i], SIGKILL);
    }
}

void execute(void)
{
    t_config *data;

    data = get_data();
    data->child_pids = malloc(sizeof(pid_t) * MAX_CHILD_PIDS);
    data->num_child_pids = 0;
    execute_cmd_list(data);
    if (data->state == EXECUTE)
        data->state = PROMPT;

    // Close open file descriptors
    close_fds(data->child_pids, data->num_child_pids);

    // Kill child processes
    kill_child_pids(data->child_pids, data->num_child_pids);

    clear_data(data);
}
