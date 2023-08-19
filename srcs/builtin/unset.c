/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_unset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 01:05:53 by viferrei          #+#    #+#             */
/*   Updated: 2023/08/18 23:35:39 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

// Frees environment list node if it matches unset argument
void	compare_arg_env(char *arg, t_config *data)
{
	t_env_list	*head;
	t_env_list	*tmp;

	if (!arg)
		return ;
	if (data->env_head && vars_match(data->env_head->content, arg))
	{
		tmp = data->env_head;
		data->env_head = data->env_head->next;
		free(tmp->content);
		free(tmp);
	}
	head = data->env_head;
	while (head && head->next)
	{
		if (vars_match(head->next->content, arg))
		{
			tmp = head->next;
			head->next = head->next->next;
			safe_free(tmp->content);
			safe_free(tmp);
		}
		else
			head = head->next;
	}
}

int	builtin_unset(char **args, t_config *data)
{
	if (!args[1])
		return (0);
	args++;
	while (*args)
	{
		compare_arg_env (*args, data);
		args++;
	}
	return (0);
}
