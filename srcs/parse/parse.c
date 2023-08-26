/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 11:13:28 by fsuomins          #+#    #+#             */
/*   Updated: 2023/08/26 02:16:40 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	categorize_and_clean_tokens(t_config *data) 
{
	categorize_tokens(data->tokens);
	remove_quotes_from_tokens(data->tokens);
	remove_invalid_redirections(&data->tokens);
	categorize_tokens(data->tokens);
}

static void	update_state_and_clear(t_config *data) 
{
	if (data->tokens == NULL)
		data->state = PROMPT;
	clear_data(data);
	if (data->state == PARSE)
		data->state = EXECUTE;
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
	remove_empty_or_whitespace_nodes(&data->tokens);
	categorize_and_clean_tokens(data);
	expand_tilde(data);
	update_state_and_clear(data);
}
