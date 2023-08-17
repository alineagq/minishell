/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 18:49:30 by fsuomins          #+#    #+#             */
/*   Updated: 2023/08/17 14:20:02 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	execute(void)
{
	t_config	*data;

	data = get_data();
	clear_data(data);
	if (data->state == EXECUTE)
		data->state = PROMPT;
}
