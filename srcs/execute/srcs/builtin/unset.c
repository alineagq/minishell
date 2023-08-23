/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 01:05:53 by viferrei          #+#    #+#             */
/*   Updated: 2023/08/23 02:44:50 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/minishell.h"

void	compare_arg_env(t_env_list **head, const char *key)
{
	t_env_list *current = *head;
	t_env_list *previous = NULL;

	while (current != NULL)
	{
		if (strcmp(current->key, key) == 0)
		{
            free(current->value);
            current->value = NULL;
            if (previous == NULL)
			{
                *head = current->next;
                free(current->key);
                free(current);
            } else {
                previous->next = current->next;
                free(current->key);
                free(current);
            }
            return;
        }
        previous = current;
        current = current->next;
    }
}

int	builtin_unset(char **args, t_com *com, t_config *data)
{
	if (!args[1])
		return (0);
	args++;
	while (*args)
	{
		compare_arg_env (&data->env, *args);
		free_char_array(com->envp);
		com->envp = tok_envp(data->env);
		args++;
	}
	return (0);
}
