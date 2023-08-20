/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 01:05:53 by viferrei          #+#    #+#             */
/*   Updated: 2023/08/20 00:21:52 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/minishell.h"

void	compare_arg_env(char *arg, t_config *data)
{
	t_env_list	*head;
	t_env_list	*tmp;

	head = data->env;
	if (!arg)
		return ;
	if (data->env && ft_strncmp (head->key, arg, ft_strlen(arg)))
	{
		tmp = data->env;
		data->env = data->env->next;
		free(tmp->key);
		free(tmp->value);
		free(tmp);
	}
	head = data->env;
	while (head && head->next)
	{
		if (ft_strncmp (head->key, arg, ft_strlen(arg)))
		{
			tmp = head->next;
			head->next = head->next->next;
			safe_free(tmp->key);
			safe_free(tmp->value);
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
