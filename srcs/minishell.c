/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 09:58:56 by fsuomins          #+#    #+#             */
/*   Updated: 2023/08/16 19:27:39 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

/**
 * Checks the validity of command line arguments.
 * Exits with status 1 if the argument count is not 1.
 * 
 * @param argc The argument count.
 * @param argv The array of command line arguments.
 */
static	void	is_valid(int argc, char **argv)
{
	(void)argv;
	if (argc != 1)
		return (exit(1));
}

/**
 * Entry point of the program.
 * Manages the execution flow based on the state of the data.
 * 
 * @param argc The argument count.
 * @param argv The array of command line arguments.
 * @return Returns 0 to indicate successful program execution.
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
			exit_program();
	}
	return (0);
}
