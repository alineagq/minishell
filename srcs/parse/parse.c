/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 11:13:28 by fsuomins          #+#    #+#             */
/*   Updated: 2023/08/26 07:49:42 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	expand_tilde(t_config *data)
{
	t_tokens	*current;
	char		*home_dir;
	char		*new_value;

	current = data->tokens;
	home_dir = getenv("HOME");
	while (current != NULL)
	{
		if (current->type == WORDTOKEN && current->value[0] == '~')
		{
			if (home_dir == NULL)
				new_value = ft_strdup(current->value);
			else
				new_value = ft_strjoin(home_dir, current->value + 1);
			free(current->value);
			current->value = new_value;
		}
		current = current->next;
	}
}

static void	remove_end_spaces(t_config *data)
{
	char		*str;

	str = ft_strtrim(data->prompt, " ");
	if (str)
	{
		free(data->prompt);
		data->prompt = str;
	}
	if (*str == '#')
	{
		data->state = PROMPT;
		return ;
	}
}

void	parse(void)
{
	t_config	*data;

	data = get_data();
	remove_end_spaces(data);
	data->parse = add_spaces(data->prompt, data);
	data->raw_tokens = create_tokens_args(data->parse, ' ');
	create_tokens(data);
	expand_exit_code(data);
	expand_variables(data);
	categorize_tokens(data->tokens);
	remove_invalid_redirections(&data->tokens);
	remove_quotes_from_tokens(data->tokens);
	categorize_tokens(data->tokens);
	expand_tilde(data);
	if (data->tokens == NULL)
		data->state = PROMPT;
	clear_data(data);
	if (data->state == PARSE)
		data->state = EXECUTE;
}
