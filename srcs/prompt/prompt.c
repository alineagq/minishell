/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 10:51:42 by fsuomins          #+#    #+#             */
/*   Updated: 2023/08/17 17:31:38 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static char	*read_line(t_config *data)
{
	char	*str;

	str = readline("minishell$ ");
	if (str == NULL)
	{
		write(STDOUT_FILENO, "exit\n", 5);
		data->exit_code = 0;
		data->state = EXIT;
	}
	else
	{
		if (*str != '\0')
		{
			add_history(str);
			return (str);
		}
		else
			free(str);
	}
	return (NULL);
}

void	prompt(void)
{
	t_config	*data;

	data = get_data();
	data->prompt = read_line(data);
	if (data->state == PROMPT && data->prompt != NULL)
		data->state = PARSE;
}
