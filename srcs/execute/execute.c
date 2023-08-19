/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 18:49:30 by fsuomins          #+#    #+#             */
/*   Updated: 2023/08/18 23:29:38 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	execute(void)
{
	t_config	*data;
	t_com		*cmd;
	int			control;
	int			original_fds[2];

	control = 1;
	original_fds[0] = NO_REDIRECT;
	original_fds[1] = NO_REDIRECT;
	while (control)
	{
		cmd = get_exec_info(data);
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
	if (data->state == EXECUTE)
		data->state = PROMPT;
}
