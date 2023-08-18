/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 09:43:36 by fsuomins          #+#    #+#             */
/*   Updated: 2023/08/18 10:12:30 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	print_env_list(t_env_list *head)
{
	t_env_list	*current;

	current = head;
	while (current != NULL)
	{
		printf("%s=%s\n", current->key, current->value);
		current = current->next;
	}
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
	while (*envp != NULL)
	{
		key = ft_strtok(*envp, "=");
		value = ft_strtok(NULL, "=");
		if (value != NULL)
			add_node(&head, &current, create_node(key, value));
		envp++;
	}
	return (head);
}

void	set_env(t_env_list **head, const char *key, const char *new_value)
{
	t_env_list	*new_node;
	t_env_list	*current;
	t_env_list	*prev;

	current = *head;
	prev = NULL;
	while (current != NULL)
	{
		if (ft_strncmp(current->key, key, ft_strlen(key)) == 0)
		{
			update_value(current, new_value);
			return ;
		}
		prev = current;
		current = current->next;
	}
	new_node = create_node(key, new_value);
	insert_node(head, prev, new_node);
}
