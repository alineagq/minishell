/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 18:49:30 by fsuomins          #+#    #+#             */
/*   Updated: 2023/08/17 03:24:44 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

#define MAX_CHILD_PIDS 100

static void	execute_pipeline(t_config *config)
{
	t_cmd	*cmd;
	int		i;
	int		fd[2];
	char	**args;
	char	*path_env;
	char	*token;
	char	*full_path;

	cmd = config->tokens;
	while (cmd != NULL)
	{
		pipe(fd);
		config->child_pids[config->num_child_pids] = fork();
		if (config->child_pids[config->num_child_pids] == 0)
		{
			if (cmd == config->tokens)
				dup2(fd[1], STDOUT_FILENO);
			else
			{
				dup2(config->fd[0], STDIN_FILENO);
				dup2(fd[1], STDOUT_FILENO);
			}
			close(fd[0]);
			close(fd[1]);
			path_env = getenv("PATH");
			token = strtok(path_env, ":");
			while (token != NULL)
			{
				full_path = ft_strjoin(token, "/");
				full_path = ft_strjoin(full_path, cmd->cmd);
				if (access(full_path, X_OK) == 0)
				{
					args = malloc(sizeof(char *) * 3);
					args[0] = cmd->cmd;
					args[1] = cmd->argv;
					args[2] = NULL;
					execve(cmd->cmd, args, config->env);
					exit(127);
				}
				free(full_path);
				token = strtok(NULL, ":");
			}
			if (token == NULL)
			{
				write(STDERR_FILENO, cmd->cmd, strlen(cmd->cmd));
				write(STDERR_FILENO, ": command not found\n", 21);
				exit(127);
			}
		}
		else if (config->child_pids[config->num_child_pids] < 0)
			perror("Fork error");
		else
		{
			close(fd[1]);
			if (cmd != config->tokens)
				close(config->fd[0]);
			config->fd[0] = fd[0];
			config->num_child_pids++;
		}
		cmd = cmd->next;
	}
	cleanup();
}

void	execute(void)
{
	t_config	*data;

	data = get_data();
	data->child_pids = malloc(sizeof(pid_t) * MAX_CHILD_PIDS);
	data->num_child_pids = 0;
	execute_pipeline(data);
	clear_data(data);
	if (data->state == EXECUTE)
		data->state = PROMPT;
}
