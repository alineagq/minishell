/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 10:37:07 by fsuomins          #+#    #+#             */
/*   Updated: 2023/08/23 16:49:23 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	handler_int(int sig)
{
	(void)sig;
	t_config	*config;

	config = get_data();
	if (config->state == PROMPT)
	{
		write(STDOUT_FILENO, "\n", 1);
		rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
	}
	else
		config->state = EXIT;
}

void	handler_quit(int sig)
{
	(void)sig;
	t_config	*config;

	config = get_data();
	config->state = EXIT;
}

void	set_signal(void)
{
	signal(SIGINT, &handler_int);
	signal(SIGQUIT, &handler_quit);
	signal(SIGTSTP, SIG_IGN);
}

void	sig_defaults(void)
{
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
	signal(SIGTERM, SIG_DFL);
}

void	ignore_signals(void)
{
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
	signal(SIGTERM, SIG_IGN);
}
