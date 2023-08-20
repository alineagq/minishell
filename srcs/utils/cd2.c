/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd2.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 00:53:10 by coder             #+#    #+#             */
/*   Updated: 2023/08/19 20:30:00 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	update_oldpwd(t_config *data, char *curr_path)
{
	t_env_list	*ls_oldpwd;

	ls_oldpwd = data->env;
	while (ls_oldpwd)
	{
		if (!ft_strncmp (ls_oldpwd->key, "OLDPWD", 6))
			break ;
		ls_oldpwd = ls_oldpwd->next;
	}
	data->oldpwd = safe_free(data->oldpwd);
	data->oldpwd = ft_strdup(curr_path);
	if (ls_oldpwd)
	{
		ls_oldpwd->value = safe_free(ls_oldpwd->value);
		ls_oldpwd->value = data->oldpwd;
		return (0);
	}
	return (1);
}

/*
** If there's a PWD node inside the environmentals, updates it.
** return 0 on success and 1 on failure;
*/
int	update_pwd(t_config *data, char *path)
{
	t_env_list	*temp;

	temp = data->env;
	while (temp)
	{
		if (!ft_strncmp(temp->key, "PWD", 3))
		{
			temp->value = safe_free(temp->value);
			temp->value = path;
			return (0);
		}
		temp = temp->next;
	}
	return (1);
}
