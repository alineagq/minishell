/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 10:37:07 by fsuomins          #+#    #+#             */
/*   Updated: 2023/08/12 19:13:30 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
/**
 * Handles the SIGINT signal (Ctrl+C).
 * 
 * This function is called when a SIGINT signal is received. If the program
 * is in interactive mode, it clears the current line and prompts for a new
 * command. If not in interactive mode, it simply writes a newline character.
 * 
 * @param sig The signal number. Should always be SIGINT in this case.
 */
void	handler_int(int sig)
{
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
		write(STDOUT_FILENO, "\n", 1);
}

/**
 * Handles the EOF signal (Ctrl+D).
 * 
 * This function is called when an EOF signal is received. If the program
 * is in interactive mode, it writes "exit\n" and then exits the program.
 * If not in interactive mode, it simply exits the program.
 * 
 * @param signum The signal number. Should always be EOF in this case.
 */
void	handle_eof(int signum)
{
	t_config	*config;

	config = get_data();

	if (config->state == PROMPT)
		write(STDOUT_FILENO, "exit\n", 5);
	config->state = EXIT;
}

/**
 * Sets up signal handling for the program.
 * 
 * This function sets the handlers for the SIGINT and SIGQUIT signals to
 * the handler_int and handle_eof functions, respectively. It also ignores
 * the SIGTSTP signal.
 * 
 * This function does not take any arguments and does not return a value.
 */
void	set_signal(void)
{
	signal(SIGINT, &handler_int);
	signal(SIGQUIT, SIG_IGN);
	signal(SIGTSTP, SIG_IGN);
}
