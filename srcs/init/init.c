/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 10:09:21 by fsuomins          #+#    #+#             */
/*   Updated: 2023/08/20 16:34:59 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	init(void)
{
	extern char	**environ;	
	t_config	*data;

	data = get_data();
	set_signal();
	data->env = create_env_list(environ);
	set_env(&data->env, "OLDPWD", "");
	set_env(&data->env, "PWD", getcwd(NULL, 0));
	if (data->state == INIT)
		data->state = PROMPT;
}
