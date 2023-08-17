/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 11:13:28 by fsuomins          #+#    #+#             */
/*   Updated: 2023/08/16 23:32:04 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/**
 * Checks if there are open quotes in the program data string.
 * 
 * This function iterates over the characters in the program data string.
 * It keeps track of the current quote state, changing it based on the 
 * encountered quotes. Single quotes change the state to 1 or reset it to 0,
 * and double quotes change the state to 2 or reset it to 0. This function does
 * not take any arguments.
 * 
 * @return 1 if there are open quotes in the string, 0 otherwise.
 */
static int	check_for_open_quotes(t_config *data)
{
	int			i;
	int			quote_state;

	i = 0;
	quote_state = 0;
	while (i < strlen(data->prompt) - 1)
	{
		if (data->prompt[i] == '\'' && quote_state != 2)
		{
			if (quote_state == 1)
				quote_state = 0;
			else
				quote_state = 1;
		}
		else if (data->prompt[i] == '\"' && quote_state != 1)
		{
			if (quote_state == 2)
				quote_state = 0;
			else
				quote_state = 2;
		}
		i++;
	}
	return (quote_state != 0);
}

/**
 * Checks if a string contains only spaces.
 * 
 * This function iterates over the characters in the string. If it encounters a
 * non-space character, it returns 0. If it reaches the end of the string without
 * encountering any non-space characters, it returns 1.
 * 
 * @param str The string to check.
 * 
 * @return 1 if the string contains only spaces, 0 otherwise.
 */
static int	is_only_space(char *str)
{
	while (str)
	{
		if (!*str)
			return (1);
		if (*str != ' ')
			return (0);
		str++;
	}
	return (1);
}


/**
 * Parses the program data string.
 * 
 * This function retrieves the program data and checks if the string is not null.
 *  If the string is not null, it checks for open quotes and whether the string 
 * is not made up of only spaces. If these conditions are met, it adds spaces to
 * the string, prints the parsed string, and then frees the memory allocated for 
 * the parsed string and the original string. Finally, it changes the program
 * state to PROMPT.
 * This function does not take any arguments and does not return a value.
 */
void	parse(void)
{
	t_config	*data;

	data = get_data();
	if (check_for_open_quotes(data))
		printf("Check for open quotes.\n");
	else if (!is_only_space(data->prompt))
	{
		data->parse = add_spaces(data->prompt);
		// printf("Prompt:%s\n", data->prompt);
		// printf("Parsed:%s\n", data->parse);
		data->raw_tokens = split_string_by_space(data->parse);
		// printf("Raw[%d]:%s\n", 0, data->raw_tokens[0]);
		// printf("Raw[%d]:%s\n", 1, data->raw_tokens[1]);
		data->tokens = create_tokens_cmd(data->raw_tokens);
		// printf("Comand:%s\n", data->tokens->cmd);
		// printf("Args:%s\n", data->tokens->argv);
	}
	if (data->state == PARSE)
		data->state = EXECUTE;
	clear_data(data);
}

