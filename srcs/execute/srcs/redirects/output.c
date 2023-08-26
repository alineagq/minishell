/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 08:50:03 by fsuomins          #+#    #+#             */
/*   Updated: 2023/08/26 08:53:45 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/minishell.h"

int	open_output_file(t_reds *out)
{
	if (out->type == OVERWRITE)
	{
		if (out->target)
			return (open(out->target, O_CREAT | O_WRONLY | O_TRUNC, 0777));
	}
	else if (out->type == APPEND)
		return (open(out->target, O_CREAT | O_WRONLY | O_APPEND, 0777));
	return (0);
}

void	redirect_output(int fd)
{
	if (fd)
	{
		dup2(fd, STDOUT_FILENO);
		close(fd);
	}
}

int	handle_output(t_reds *red_out, int original_fds[2])
{
	t_reds	*out;
	int		fd;

	out = red_out;
	fd = 0;
	if (!out)
	{
		return (0);
	}
	if (original_fds[1] == NO_REDIRECT)
	{
		original_fds[1] = dup(STDOUT_FILENO);
	}
	while (out)
	{
		fd = open_output_file(out);
		redirect_output(fd);
		out = out->next;
	}
	return (0);
}
