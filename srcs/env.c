/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 10:00:00 by fsuomins          #+#    #+#             */
/*   Updated: 2023/08/04 10:03:34 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	print_env(void)
{
	t_config	*config;
	int			i;

	config = get_data();

	while (config->env)
		printf("%s\n", config->env[i++]);
}
