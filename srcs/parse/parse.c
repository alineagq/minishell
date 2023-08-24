/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 11:13:28 by fsuomins          #+#    #+#             */
/*   Updated: 2023/08/24 14:09:38 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	check_for_open_quotes(char *prompt)
{
	int	i;
	int	single_quotes;
	int	double_quotes;

	i = 0;
	single_quotes = 0;
	double_quotes = 0;
	while (prompt[i])
	{
		if (prompt[i] == '\'' && (double_quotes % 2 == 0))
			single_quotes++;
		if (prompt[i] == '\"' && (single_quotes % 2 == 0))
			double_quotes++;
		i++;
	}
	return ((single_quotes % 2) + (double_quotes % 2));
}

int	is_only_space(char *str)
{
	if (str && !*str)
		return (0);
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

static int	promp_is_valid(t_config *data)
{
	if (check_for_open_quotes(data->prompt))
	{
		printf("Check for open quotes.\n");
		data->exit_code = 2;
		data->state = PROMPT;
		return (0);
	}
	else if (is_only_space(data->prompt))
	{
		data->state = PROMPT;
		if (!data->set_buffer_to_null)
			free(data->prompt);
		return (0);
	}
	return (1);
}

void	parse(void)
{
	t_config	*data;

	data = get_data();
	if (promp_is_valid(data))
	{
		data->parse = add_spaces(data->prompt, data);
		data->raw_tokens = create_tokens_args(data->parse, ' ');
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
