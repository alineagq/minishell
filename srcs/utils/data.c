/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 16:06:48 by fsuomins          #+#    #+#             */
/*   Updated: 2023/08/18 11:49:00 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_config	*get_data(void)
{
	static t_config	data;

	return (&data);
}

void	clear_data(t_config	*data)
{
	if (data->state == EXIT)
		clear_env(data);
	close_inherited_fds();
}
