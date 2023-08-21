/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 11:13:28 by fsuomins          #+#    #+#             */
/*   Updated: 2023/08/21 16:56:34 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	check_for_open_quotes(char *rl_buffer)
{
	int	i;
	int	sinquotes;
	int	douquotes;

	i = 0;
	sinquotes = 0;
	douquotes = 0;
	while (rl_buffer[i])
	{
		if (rl_buffer[i] == '\'' && (douquotes % 2 == 0))
			sinquotes++;
		if (rl_buffer[i] == '\"' && (sinquotes % 2 == 0))
			douquotes++;
		i++;
	}
	return ((sinquotes % 2) + (douquotes % 2));
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
	if (check_for_open_quotes(data->prompt))
	{
		printf("Check for open quotes.\n");
		data->exit_code = 2;
		data->state = PROMPT;
	}
	else if (!is_only_space(data->prompt))
	{
		data->parse = add_spaces(data->prompt, data);
		data->raw_tokens = ft_split_shell(data->parse, ' ');
		create_tokens(data);
		expand_exit_code(data);
		expand_variables(data);
		categorize_tokens(data->tokens);
		remove_quotes_from_tokens(data->tokens);
	}
	clear_data(data);
	if (data->state == PARSE)
		data->state = EXECUTE;
}
