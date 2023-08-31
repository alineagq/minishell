/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 09:58:56 by fsuomins          #+#    #+#             */
/*   Updated: 2023/08/30 20:50:53 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	main(void)
{
	t_config	*data;

	data = get_data();
	data->state = INIT;
	while (1)
	{
		if (data->state == INIT)
			init();
		if (data->state == PROMPT)
			prompt();
		if (data->state == PARSE)
			parse();
		if (data->state == EXIT)
			exit_program();
	}
}
