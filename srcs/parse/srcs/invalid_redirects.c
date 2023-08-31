/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   invalid_redirects.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 07:47:21 by fsuomins          #+#    #+#             */
/*   Updated: 2023/08/26 07:55:11 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

static int	is_valid_file(char *filename)
{
	if (access(filename, F_OK) != -1)
		return (1);
	return (0);
}

static int	is_valid_redirection(t_tokens *current)
{
	int	type_is;

	type_is = current->type;
	if (type_is == 1 && current->type == REDTOKEN && \
		is_valid_file(current->next->value))
		return (1);
	return (0);
}

static void	remove_redirection_node(t_tokens **head, t_tokens *node)
{
	t_tokens	*prev;
	t_tokens	*next;

	prev = node->prev;
	next = node->next;
	if (prev != NULL)
		prev->next = next;
	else
		*head = next;
	if (next != NULL)
		next->prev = prev;
	free(node->value);
	free(node);
}

void	remove_invalid_redirections(t_tokens **head)
{
	t_tokens	*current;
	t_tokens	*next_next;

	current = *head;
	while (current != NULL && current->next != NULL)
	{
		if (is_valid_redirection(current) == 1)
		{
			next_next = current->next->next;
			remove_redirection_node(head, current);
			current = next_next;
		}
		else
		{
			current = current->next;
		}
	}
}
