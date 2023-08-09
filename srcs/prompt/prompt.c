/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 10:51:42 by fsuomins          #+#    #+#             */
/*   Updated: 2023/08/06 11:47:59 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	prompt(void)
{
	t_config	*data;

	data = get_data();
	data->interactive_mode = 1;
	data->str = read_line();
	data->state = PARSE;
}

char	*read_line(void)
{
	char	*str;

	str = readline("minishell$ ");
	if (str == NULL)
	{
		write(STDOUT_FILENO, "exit\n", 5);
		exit(EXIT_SUCCESS);
	}
	if (*str)
		add_history(str);
	else
	{
		free(str);
		str = NULL;
	}
	return (str);
}

