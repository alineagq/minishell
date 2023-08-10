/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 11:13:28 by fsuomins          #+#    #+#             */
/*   Updated: 2023/08/10 00:01:39 by fsuomins         ###   ########.fr       */
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
static int	check_for_open_quotes(void)
{
	t_config	*data;
	int			i;
	int			quote_state;

	data = get_data();
	i = 0;
	quote_state = 0;
	while (i < strlen(data->str) - 1)
	{
		if (data->str[i] == '\'' && quote_state != 2)
		{
			if (quote_state == 1)
				quote_state = 0;
			else
				quote_state = 1;
		}
		else if (data->str[i] == '\"' && quote_state != 1)
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
	if (data->str)
	{
		if (check_for_open_quotes())
			printf("Check for open quotes.");
		if (!is_only_space(data->str))
		{
			data->parse = add_spaces(data->str);
			data->raw_tokens = split_string_by_space(data->parse);
			// data-> t_list **tokens = create_tokens_list(char **raw_tokens)
			// typedef struct t_list *next, char *cmd, char **args;
			print_char_array(data->raw_tokens);
			free_char_array(data->raw_tokens);
			// printf("%s\n", data->parse);
			free(data->parse);
			free(data->str);
		}
	}
	data->state = PROMPT;
}
