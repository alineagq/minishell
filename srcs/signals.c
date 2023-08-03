/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 09:36:50 by fsuomins          #+#    #+#             */
/*   Updated: 2023/08/03 11:12:16 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	handler_int(int sig)
{
	t_config	*config;

	config = get_data();
	if (config->interactive_mode)
	{
		write(STDOUT_FILENO, "\n", 1);
		rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
	}
	else
		write(STDOUT_FILENO, "\n", 1);
}

void	handle_eof(int signum)
{
	t_config	*config;

	config = get_data();

	if (config->interactive_mode)
	{
		write(STDOUT_FILENO, "exit\n", 5);
		clean_up();
		exit(EXIT_SUCCESS);
	}
	else
	{
		clean_up();
		exit(EXIT_SUCCESS);
	}
}

void	set_signal(void)
{
	signal(SIGINT, &handler_int);
	signal(SIGQUIT, SIG_IGN);
	signal(SIGTSTP, SIG_IGN);
}
