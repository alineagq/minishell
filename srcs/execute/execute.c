/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 18:49:30 by fsuomins          #+#    #+#             */
/*   Updated: 2023/08/23 01:03:50 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include <stdio.h>

void print_t_com(t_com com)
{
    printf("t_com:\n");
    printf("block_exec: %d\n", com.block_exec);
    printf("command: %s\n", com.command);
    printf("is_builtin: %d\n", com.is_builtin);
    printf("args:\n");
    for (int i = 0; com.args[i] != NULL; i++)
    {
        printf("  %s\n", com.args[i]);
    }
    printf("envp:\n");
    for (int i = 0; com.envp[i] != NULL; i++)
    {
        printf("  %s\n", com.envp[i]);
    }
    printf("red_in:\n");
    while (com.red_in != NULL)
    {
        printf("  type: %d\n", com.red_in->type);
        printf("  target: %s\n", com.red_in->target);
        com.red_in = com.red_in->next;
    }
    printf("red_out:\n");
    while (com.red_out != NULL)
    {
        printf("  type: %d\n", com.red_out->type);
        printf("  target: %s\n", com.red_out->target);
        com.red_out = com.red_out->next;
    }
    printf("receives_from_pipe: %d\n", com.receives_from_pipe);
    printf("sends_to_pipe: %d\n", com.sends_to_pipe);
    printf("error_to_print: %s\n", com.error_to_print);
}

static void	create_redirect_files(t_com *cmd)
{
	t_reds	*tmp;

	tmp = cmd->red_out;
	while (tmp)
	{
		open(tmp->target, O_CREAT | O_RDONLY, 0777);
		tmp = tmp->next;
	}
}


static int	exec_loop(t_com *cmd, t_config *data, int original_fds[2])
{
	if (!cmd)
		return (0);
	if (cmd->block_exec)
	{
		write (2, cmd->error_to_print, ft_strlen(cmd->error_to_print));
		return (0);
	}
	create_redirect_files(cmd);
	if (!cmd->receives_from_pipe && !cmd->sends_to_pipe)
	{
		exec_one_cmd(cmd, data, original_fds);
		return (0);
	}
	else if (!data->issue_exit)
		return (exec_multi(cmd, data, original_fds));
	return (1);
}

void	execute(void)
{
	t_config	*data;
	t_com		*cmd;
	int			control;
	int			original_fds[2];

	control = 1;
	original_fds[0] = NO_REDIRECT;
	original_fds[1] = NO_REDIRECT;
	ignore_signals();
	data = get_data();
	while (control)
	{
		cmd = get_exec_info(data);
		// print_t_com(*cmd);
		control = exec_loop(cmd, data, original_fds);
		destroy_exec_info(cmd);
		if (data->issue_exit)
			break ;
	}
	while (wait(&data->exit_code) > 0)
		continue ;
	if (data->exit_code >= 256)
		data->exit_code = data->exit_code >> 8;
	restore_original_fds(original_fds);
	data = get_data();
	clear_data(data);
	if (data->issue_exit)
		data->state = EXIT;
	if (data->state == EXECUTE)
		data->state = PROMPT;
}
