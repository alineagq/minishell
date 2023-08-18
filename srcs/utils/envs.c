/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 15:45:47 by fsuomins          #+#    #+#             */
/*   Updated: 2023/08/18 10:16:51 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	add_node(t_env_list **head, t_env_list **cur, t_env_list *new)
{
	if (new == NULL)
		return ;
	if (*head == NULL)
		*head = new;
	else
		(*cur)->next = new;
	*cur = new;
}

t_env_list	*create_node(const char *key, const char *value)
{
	t_env_list	*node;

	node = (t_env_list *)malloc(sizeof(t_env_list));
	if (node == NULL)
		return (NULL);
	node->key = ft_strdup(key);
	node->value = ft_strdup(value);
	node->next = NULL;
	return (node);
}

void	update_value(t_env_list *node, const char *new_value)
{
	if (node == NULL)
		return ;
	if (node->value != NULL)
		free(node->value);
	node->value = ft_strdup(new_value);
}

void	insert_node(t_env_list **head, t_env_list *prev, t_env_list *new)
{
	if (new == NULL)
		return ;
	if (prev == NULL)
	{
		new->next = *head;
		*head = new;
	}
	else
	{
		new->next = prev->next;
		prev->next = new;
	}
}
