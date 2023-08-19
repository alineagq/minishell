/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 11:13:28 by fsuomins          #+#    #+#             */
/*   Updated: 2023/08/18 14:52:42 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	check_for_open_quotes(t_config *data)
{
	int			i;
	int			quote_state;

	i = 0;
	quote_state = 0;
	while (i < strlen(data->prompt) - 1)
	{
		if (data->prompt[i] == '\'' && quote_state != 2)
		{
			if (quote_state == 1)
				quote_state = 0;
			else
				quote_state = 1;
		}
		else if (data->prompt[i] == '\"' && quote_state != 1)
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
	int			i;

	i = 0;
	data = get_data();
	if (check_for_open_quotes(data))
	{
		printf("Check for open quotes.\n");
		data->exit_code = 2;
	}
	else if (!is_only_space(data->prompt))
	{
		data->parse = add_spaces(data->prompt, data);
		data->raw_tokens = ft_split_shell(data->parse, ' ');
		create_tokens(data);
		expand_exit_code(data);
		expand_variables(data);
	}
	clear_data(data);
	if (data->state == PARSE)
		data->state = PROMPT;
}
