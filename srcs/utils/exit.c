/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 14:42:20 by fsuomins          #+#    #+#             */
/*   Updated: 2023/08/17 15:47:54 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	close_inherited_fds(int preserve_fds[])
{
	int	max_fd;

	max_fd = sysconf(_SC_OPEN_MAX);
	for (int fd = 3; fd < max_fd; fd++)
	{
		int close_fd = 1;

		for (int i = 0; preserve_fds[i] != -1; i++)
		{
			if (fd == preserve_fds[i])
			{
				close_fd = 0;
				break ;
			}
		}
		if (close_fd)
			close(fd);
	}
}
