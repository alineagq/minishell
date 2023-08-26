/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 18:49:30 by fsuomins          #+#    #+#             */
/*   Updated: 2023/08/26 04:12:47 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"



void	create_redirect_files(t_com *cmd)
{
	t_reds	*tmp;

	tmp = cmd->red_out;
	while (tmp)
	{
		if (tmp->target)
			open(tmp->target, O_CREAT | O_RDONLY, 0777);
		tmp = tmp->next;
	}
}

void	execute(void)
{
	t_config	*data;
	int			original_fds[2];

	initialize(&data, original_fds);
	execution_loop(data, original_fds);
	clean_state(data);
	clear_data(data);
	finalize(data);
}

