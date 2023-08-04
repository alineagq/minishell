/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 10:28:57 by fsuomins          #+#    #+#             */
/*   Updated: 2023/08/04 10:24:24 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	init_shell(void)
{
	extern char	**environ;
	t_config	*config;

	config = get_data();
	config->env = environ;
	config->interactive_mode = 1;
	if (!isatty(STDIN_FILENO))
		config->interactive_mode = 0;
	set_signal();
}
