/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spaces.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 14:45:24 by fsuomins          #+#    #+#             */
/*   Updated: 2023/08/14 21:58:42 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/**
 * Checks if a character is a delimiter.
 * 
 * This function takes a character as input and checks if it is a delimiter.
 * Delimiters include '|', '>', and '<'.
 * 
 * @param c The character to check.
 * 
 * @return 1 if the character is a delimiter, 0 otherwise.
 */
int	is_delimiter(char c)
{
	return (c == '|' || c == '>' || c == '<');
}

/**
 * Checks if a character is a whitespace character.
 *
 * @param c The character to be checked.
 * @return 1 if the character is a whitespace character (space, tab,
 * newline, carriage return, form feed, vertical tab), 0 otherwise.
 */
int	is_whitespace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n' || c == '\r' \
	|| c == '\f' || c == '\v');
}

/**
 * Checks if a space needs to be added before a character at a given
 * index in the input string.
 *
 * @param i     The index of the character being checked.
 * @param input The input string to analyze.
 * @return 1 if a space is needed before the character, 0 otherwise.
 */
static int	check_if_need_space(size_t i, char *input)
{
	return (i != 0 && is_delimiter(input[i]) && (input[i] != input[i - 1]) \
	&& !is_whitespace(input[i - 1]));
}

/**
 * Checks if a space needs to be added between two adjacent characters
 * at a given index and the next index in the input string.
 *
 * @param i     The index of the first character being checked.
 * @param len   The length of the input string.
 * @param input The input string to analyze.
 * @return 1 if a space is needed between the characters, 0 otherwise.
 */
static int	check_spaces_double_token(size_t i, size_t len, char *input)
{
	return (i != len - 1 && is_delimiter(input[i]) && input[i] != input[i + 1]);
}

/**
 * Adds spaces to the input string based on specified conditions.
 *
 * @param input The input string to which spaces will be added.
 * @return A new dynamically allocated string with added spaces, or NULL
 * if memory allocation fails. The caller is responsible for freeing the
 * memory allocated for the returned string.
 */
char	*add_spaces(char *input)
{
	size_t	len;
	size_t	size;
	char	*result;
	size_t	i;

	len = strlen(input);
	size = 0;
	i = 0;
	result = (char *)malloc(sizeof(char) * (len * 2 + 1));
	if (!result)
	{
		perror("Memory allocation failed");
		return (NULL);
	}
	while (i < len)
	{
		if (check_if_need_space(i, input))
			result[size++] = ' ';
		result[size++] = input[i];
		if (check_spaces_double_token(i, len, input))
			result[size++] = ' ';
		i++;
	}
	result[size] = '\0';
	return (result);
}
