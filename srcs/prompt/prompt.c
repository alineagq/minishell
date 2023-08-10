/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 10:51:42 by fsuomins          #+#    #+#             */
/*   Updated: 2023/08/09 17:39:50 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
/**
 * Sets the program into interactive mode and reads a line from the user.
 * 
 * This function retrieves the program data, sets the program into interactive
 * mode, and reads a line from the user using the `read_line` function. If the
 * line read is not null, it changes the program state to PARSE.
 * 
 * This function does not take any arguments and does not return a value.
 */
void	prompt(void)
{
	t_config	*data;

	data = get_data();
	data->interactive_mode = 1;
	data->str = read_line();
	data->state = PARSE;
}

/**
 * Reads a line from the user with the prompt "minishell$ ".
 * 
 * This function uses the readline function to read a line from the user with the prompt "minishell$ ".
 * If the line read is null, it writes "exit\n" and exits the program. If the line read is not empty,
 * it adds the line to the readline history. If the line read is empty, it frees the memory allocated
 * for the line and sets the line to null.
 * 
 * This function does not take any arguments.
 * 
 * @return The line read from the user, or null if the line was empty.
 */
char	*read_line(void)
{
	char	*str;

	str = readline("minishell$ ");
	if (str == NULL)
	{
		write(STDOUT_FILENO, "exit\n", 5);
		exit(EXIT_SUCCESS);
	}
	if (*str)
		add_history(str);
	else
	{
		free(str);
		str = NULL;
	}
	return (str);
}

