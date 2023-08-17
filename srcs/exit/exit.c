/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 14:07:41 by fsuomins          #+#    #+#             */
/*   Updated: 2023/08/17 14:01:49 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void cleanup()
{
    pid_t result = 0;
    
    while (result > 0 || (result == -1 && errno == EINTR))
    {
        result = waitpid(-1, NULL, WNOHANG);
    }
}

void	exit_program(void)
{
	t_config	*data;

	data = get_data();
	clear_data(data);
	exit(data->exit_code);
}
