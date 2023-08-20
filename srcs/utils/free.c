/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 08:22:10 by fsuomins          #+#    #+#             */
/*   Updated: 2023/08/19 18:10:21 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	free_tokens(t_tokens *tokens)
{
	t_tokens	*temp;

	while (tokens)
	{
		temp = tokens;
		tokens = tokens->next;
		free(temp->value);
		free(temp);
	}
}

void	free_char_array(char **arr)
{
	int		i;

	if (arr == NULL)
		return ;
	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	clear_env(t_config *data)
{
	t_env_list	*current;
	t_env_list	*next;

	current = data->env;
	while (current != NULL)
	{
		next = current->next;
		free(current->key);
		current->key = NULL;
		free(current->value);
		current->value = NULL;
		free(current);
		current = next;
	}
	data->env = NULL;
}

void	*safe_free(void *content)
{
	if (content != NULL)
	{
		free (content);
		content = NULL;
		return (NULL);
	}
	return (NULL);
}
