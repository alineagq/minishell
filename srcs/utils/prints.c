/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prints.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 14:38:25 by fsuomins          #+#    #+#             */
/*   Updated: 2023/08/17 17:10:18 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	print_structs(t_config *config)
{
	if (config != NULL)
	{
		// if (config->env != NULL)
		// 	printf("env: %s\n", *(config->env));
		if (config->prompt != NULL)
			printf("prompt: %s\n", config->prompt);
		if (config->parse != NULL)
			printf("parse: %s\n", config->parse);
		if (config->raw_tokens != NULL)
			printf("raw_tokens: %s\n", *(config->raw_tokens));
		printf("exit_code: %d\n", config->exit_code);
		printf("state: %d\n", config->state);
		printf("num_child_pids: %d\n", config->num_child_pids);
		printf("pipe: %d, %d\n", config->pipe[0], config->pipe[1]);

		t_cmd *cmd = config->tokens;
		while (cmd != NULL)
		{
			if (cmd->cmd != NULL)
				printf("cmd: %s\n", cmd->cmd);
			if (cmd->argv != NULL)
				printf("argv: %s\n", cmd->argv);
			cmd = cmd->next;
		}

		pid_t *pids = config->child_pids;
		for (int i = 0; i < config->num_child_pids; i++)
		{
			printf("child_pid: %d\n", pids[i]);
		}
	}
	else
		printf("The struct t_config is NULL.\n");
}
