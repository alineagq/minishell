/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 10:28:57 by fsuomins          #+#    #+#             */
/*   Updated: 2023/08/02 20:17:48 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	init_shell(char **envs)
{
	int	i;

	i = 0;
	while (envs[i])
		printf("%s\n", envs[i++]);
	set_signal();
}
