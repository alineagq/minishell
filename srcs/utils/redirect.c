/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 03:52:44 by viferrei          #+#    #+#             */
/*   Updated: 2023/08/23 10:19:04 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	restore_original_fds(int original_fds[2])
{
	close_inherited_fds();
	if (original_fds[0] != NO_REDIRECT)
		dup2(original_fds[0], STDIN_FILENO);
	if (original_fds[1] != NO_REDIRECT)
		dup2(original_fds[1], STDOUT_FILENO);
	return (1);
}
