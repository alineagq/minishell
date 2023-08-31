/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 11:13:28 by fsuomins          #+#    #+#             */
/*   Updated: 2023/08/30 20:12:41 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

// static void	categorize_and_clean_tokens(t_config *data)
// {
// 	categorize_tokens(data->tokens);
// 	remove_quotes_from_tokens(data->tokens);
// 	remove_invalid_redirections(&data->tokens);
// 	categorize_tokens(data->tokens);
// }

static void	update_state_and_clear(t_config *data)
{
	if (data->tokens == NULL)
		data->state = PROMPT;
	clear_data(data);
	if (data->state == PARSE)
		data->state = PROMPT;
}

void	parse(void)
{
	t_config	*data;

	data = get_data();
	data->parse = add_spaces(data->prompt);
	printf("data: %s\n", data->parse);
	update_state_and_clear(data);
}
