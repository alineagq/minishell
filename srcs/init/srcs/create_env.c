/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 01:17:48 by fsuomins          #+#    #+#             */
/*   Updated: 2023/08/26 03:03:47 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

static void	add_node(t_env_list **head, t_env_list **cur, t_env_list *new)
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

t_env_list	*create_env_list(char **env)
{
	t_env_list	*head;
	t_env_list	*current;
	char		**envp;
	char		*key;
	char		*value;

	head = NULL;
	current = NULL;
	envp = env;
	while (*envp)
	{
		key = ft_strdup(*envp);
		value = ft_strchr(key, '=');
		if (value)
		{
			*value = '\0';
			value++;
			add_node(&head, &current, create_node(key, value));
			free(key);
		}
		envp++;
	}
	return (head);
}
