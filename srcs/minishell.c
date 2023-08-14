/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 09:58:56 by fsuomins          #+#    #+#             */
/*   Updated: 2023/08/13 21:17:15 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static	void	is_valid(int argc, char **argv)
{
	(void)argv;
	if (argc != 1)
		return (exit(1));
}

/**
 * Main function of the program.
 * 
 * This function initializes the program state and then enters into an infinite
 * loop. Within the loop, it checks the current state of the program and calls
 * the appropriate function based on that state.
 * 
 * The states and their associated functions are as follows:
 * - INIT: Calls the init function.
 * - PROMPT: Calls the prompt function.
 * - PARSE: Calls the parse function.
 * 
 * The state is initially set to INIT and is expected to be updated within the
 * called functions.
 * 
 * @return 0 under normal operation. The infinite loop is expected to be broken
 * by external means such as a signal. If the loop is broken, the function 
 * returns 0.
 */
int	main(int argc, char **argv)
{
	t_config	*data;	

	is_valid(argc, argv);
	data = get_data();
	data->state = INIT;
	while (1)
	{
		if (data->state == INIT)
			init(); 
		if (data->state == PROMPT)
			prompt();
		if (data->state == PARSE)
			parse();
		if (data->state == EXECUTE)
			execute();
		if (data->state == EXIT)
		{
			free(data->env);
			exit(data->exit_code);
		}
	}
	return (0);
}
