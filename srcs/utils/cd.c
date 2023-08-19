/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 23:24:07 by coder             #+#    #+#             */
/*   Updated: 2023/08/19 00:24:08 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/*
** returns a copy of the path, expanding ~'s
** returns NULL on failure;
*/
char	*expand_home(char *path, t_config *data)
{
	char	*home;

	if (path[0] != '~' && path[0] != '-')
		return (ft_strdup(path));
	if (path[0] == '-')
		return (ft_strdup(data->oldpwd));
	home = get_home_dir_from_envs(data);
	if (!home)
		home = data->home_original;
	return (ft_strjoin(home, path + 1));
}

/*
** Counts the number of args in args and returns it. Really.
*/
int	count_args(char **args)
{
	int	i;

	i = 0;
	if (!args)
		return (0);
	while (args[i])
	{
		i++;
	}
	return (i);
}

/*
** Gets HOME string address from env list.
** Returns the address of the string if it exists, else returns NULL.
*/
char	*get_home_dir_from_envs(t_config *data)
{
	t_env_list	*temp;

	temp = data->env;
	while (temp)
	{
		if (!ft_strncmp (temp->content, "HOME=", 5))
		{
			if (ft_strlen(temp->content) > PATH_MAX)
			{
				write (2, "cd: HOME too big to fit in here\n", 17);
				data->exit_code = 1;
				return (NULL);
			}
			return (temp->content + 5);
		}
		temp = temp->next;
	}
	data->exit_code = 1;
	return (NULL);
}

/*
** Norminette can be a bitch.
*/
int	cd_error_args(t_config *data)
{
	write(2, "cd: too many freaking arguments\n", 32);
	data->exit_code = 1;
	return (data->exit_code);
}
