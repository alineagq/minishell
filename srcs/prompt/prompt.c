/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 10:51:42 by fsuomins          #+#    #+#             */
/*   Updated: 2023/08/16 17:47:35 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/**
 * Read a line of input from the user, process it, and update the shell's
 * state.
 *
 * This function reads a line of input from the user, displays a prompt,
 * and stores the entered line in a dynamically allocated string. If the
 * input is empty (just Enter), the allocated memory is freed. If the input
 * is the "exit" command, the function sets the shell's exit code and state
 * accordingly. The entered line can also be added tothe shell's history.
 *
 * @param data A pointer to the shell's configuration data.
 * @return A dynamically allocated string containing the user's input, or
 * NULL if input is empty.
 *         The caller is responsible for freeing the returned string.
 */
static char	*read_line(t_config *data)
{
	char	*str;

	str = readline("minishell$ ");
	if (str == NULL)
	{
		write(STDOUT_FILENO, "exit\n", 5);
		data->exit_code = 0;
		data->state = EXIT;
	}
	else
	{
		if (*str != '\0')
		{
			add_history(str);
			return (str);
		}
		else
			free(str);
	}
	return (NULL);
}

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
	data->prompt = read_line(data);
	if (data->state == PROMPT && data->prompt != NULL)
		data->state = PARSE;
}
