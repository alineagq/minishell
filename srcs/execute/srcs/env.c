/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 03:04:27 by coder             #+#    #+#             */
/*   Updated: 2023/08/23 10:07:27 by fsuomins         ###   ########.fr       */
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
	char	*temp2;

	i = 0;
	while (head && i < top - 1)
	{
		temp2 = ft_strdup(head->key);
		temp = ft_strjoin(temp2, "=");
		ret[i] = ft_strjoin(temp, head->value);
		free(temp);
		free(temp2);
		i++;
		head = head->next;
	}
	ret[i] = NULL;
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
