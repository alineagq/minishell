/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_pwd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 19:45:04 by coder             #+#    #+#             */
/*   Updated: 2023/08/18 23:35:39 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/*
** Uses getcwd to check for current working directory even is the env PWD is
** unset. Just like bash' pwd command.
*/
int	builtin_pwd(char **args, char **envp, t_config *data)
{
	char	path_name[PATH_MAX];

	(void) args;
	(void) envp;
	if (!getcwd(path_name, PATH_MAX))
	{
		write (2, "Error: user is trying to fuck shit up!\n", 40);
		data->exit_code = 1;
		return (1);
	}
	printf("%s\n", path_name);
	data->exit_code = 0;
	return (0);
}
