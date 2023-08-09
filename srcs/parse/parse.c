/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 11:13:28 by fsuomins          #+#    #+#             */
/*   Updated: 2023/08/08 20:28:58 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	check_for_open_quotes(void)
{
	t_config	*data;
	int			i;
	int			quote_state;

	data = get_data();
	i = 0;
	quote_state = 0;
	while (i < strlen(data->str) - 1)
	{
		if (data->str[i] == '\'' && quote_state != 2)
		{
			if (quote_state == 1)
				quote_state = 0;
			else
				quote_state = 1;
		}
		else if (data->str[i] == '\"' && quote_state != 1)
		{
			if (quote_state == 2)
				quote_state = 0;
			else
				quote_state = 2;
		}
		i++;
	}
	return (quote_state != 0);
}

static int	is_only_space(char *str)
{
	while (str)
	{
		if (!*str)
			return (1);
		if (*str != ' ')
			return (0);
		str++;
	}
	return (1);
}

void	parse(void)
{
	t_config	*data;

	data = get_data();
	if (data->str)
	{
		if (check_for_open_quotes())
			printf("Check for open quotes.");
		if (!is_only_space(data->str))
		{
			data->parse = add_spaces(data->str);
			printf("%s\n", data->parse);
			free(data->parse);
			free(data->str);
		}
	}
	data->state = PROMPT;
}
