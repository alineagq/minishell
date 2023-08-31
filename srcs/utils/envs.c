/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 15:45:47 by fsuomins          #+#    #+#             */
/*   Updated: 2023/08/26 09:25:11 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*get_env_value(t_env *head, char *targetKey)
{
	t_env	*current;

	current = head;
	while (current != NULL)
	{
		if (ft_strcmp(current->key, targetKey) == 0)
			return (current->value);
		current = current->next;
	}
	return (NULL);
}

void	print_env(t_env *head)
{
	t_env	*current;

	current = head;
	while (current != NULL)
	{
		printf("%s=%s\n", current->key, current->value);
		current = current->next;
	}
}

void	print_export_list(t_env *head)
{
	t_env	*current;

	current = head;
	while (current != NULL)
	{
		printf("declare -x %s=\"%s\"\n", current->key, current->value);
		current = current->next;
	}
}
