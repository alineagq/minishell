/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaner.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 10:25:28 by fsuomins          #+#    #+#             */
/*   Updated: 2023/07/28 10:27:26 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	clean_up(void)
{
	pid_t	result;

	result = 0;
	while ((result > 0 || result == -1) && errno == EINTR)
	{
		result = waitpid(-1, NULL, WNOHANG);
	}
}
