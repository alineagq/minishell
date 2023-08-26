/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 00:12:09 by fsuomins          #+#    #+#             */
/*   Updated: 2023/08/26 04:04:53 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	expand_tilde(t_config *data)
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

static int	is_valid_file(char *filename)
{
	if (access(filename, F_OK) != -1)
	{
		return (1);
	}
	else
		return (0);
}

static void	free_and_advance_tokens(t_tokens **prev, t_tokens **current, \
			t_tokens **head, t_tokens **next_next)
{
	if (*prev != NULL)
		(*prev)->next = *next_next;
	else
		*head = *next_next;
	if (*next_next != NULL)
		(*next_next)->prev = *prev;
	free((*current)->value);
	free((*current)->next->value);
	free((*current)->next);
	free(*current);
	*current = *next_next;
}

void	remove_invalid_redirections(t_tokens **head)
{
	t_tokens	*current;
	t_tokens	*prev;
	int			type_is;

	current = *head;
	prev = NULL;
	type_is = current->type;
	while (current != NULL && current->next != NULL)
	{
		if (type_is == 1 && current->type == REDTOKEN && \
			is_valid_file(current->next->value))
			free_and_advance_tokens(&prev, &current, head, \
				&current->next->next);
		else
		{
			prev = current;
			current = current->next;
		}
	}
}

void	remove_end_spaces(t_config *data)
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
