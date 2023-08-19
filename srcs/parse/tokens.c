/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 14:44:30 by fsuomins          #+#    #+#             */
/*   Updated: 2023/08/18 23:20:32 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	create_tokens(t_config *data)
{
	int			i;
	t_tokens	*self;
	t_tokens	*temp;
	t_tokens	*previous;

	if (!data->raw_tokens || !data->raw_tokens[0])
		data->tokens = NULL;
	i = 0;
	self = ft_calloc(1, sizeof(*self));
	temp = self;
	temp->prev = NULL;
	while (data->raw_tokens[i])
	{
		temp->value = ft_strdup(data->raw_tokens[i]);
		if (data->raw_tokens[i + 1])
			temp->next = ft_calloc(1, sizeof(*self));
		previous = temp;
		temp = temp->next;
		if (temp)
			temp->prev = previous;
		i++;
	}
	data->tokens = self;
}

static int	set_tok_indexes(t_tokens *tokens)
{
	t_tokens	*temp;
	int			i;

	temp = tokens;
	i = 0;
	while (temp)
	{
		temp->index = i;
		i++;
		temp = temp->next;
	}
	return (i);
}

void	categorize_tokens(t_tokens *tokens)
{
	t_tokens	*temp;

	temp = tokens;
	set_tok_indexes(tokens);
	while (temp)
	{
		temp->type = get_token_type(temp);
		if (temp->type == REDTOKEN || temp->type == OPTOKEN)
			if (token_is_error(temp))
				temp->type = ERRTOKEN;
		temp = temp->next;
	}
}

int	check_for_non_print(char *value)
{
	int	count;

	count = 0;
	while (value[count])
	{
		if (!ft_isprint(value[count]) && (value[count] != 0))
			return (0);
		count++;
	}
	return (1);
}
