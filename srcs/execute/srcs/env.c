/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 03:04:27 by coder             #+#    #+#             */
/*   Updated: 2023/08/20 03:41:40 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

static int	count_envs(t_env_list *head)
{
	t_env_list	*temp;
	int			i;

	temp = head;
	i = 0;
	while (temp)
	{
		temp = temp->next;
		i++;
	}
	return (i);
}

static void	tok_fill_envp(char **ret, t_env_list *head, int top)
{
	int		i;
	char	*temp;

	i = 0;
	while (head && i < top - 1)
	{
		temp = ft_strjoin(ft_strdup(head->key), "=");
		ret[i] = ft_strjoin(temp, head->value);
		// printf("ret[%d] = %s\n", i, ret[i]);
		free(temp);
		i++;
		head = head->next;
	}
}


char	**tok_envp(t_env_list *head)
{
	t_env_list	*temp;
	int			count;
	char		**ret;

	temp = head;
	count = count_envs(temp);
	if (!count)
		return (0);
	ret = ft_calloc(count, sizeof(*ret));
	tok_fill_envp(ret, temp, count);
	return (ret);
}
