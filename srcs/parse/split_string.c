/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 23:44:21 by fsuomins          #+#    #+#             */
/*   Updated: 2023/08/16 16:32:22 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/**
 * Checks if a character is a single or double quote.
 *
 * @param c The character to be checked.
 * @return 1 if the character is a single or double quote, 0 otherwise.
 */
int	is_quote(const char c)
{
	return (c == '\'' || c == '"');
}

/**
 * Counts the number of tokens (words) in a given string separated by spaces,
 * excluding those within quotes.
 *
 * @param str The input string to be tokenized.
 * @return The number of tokens in the string.
 */
static size_t	count_tokens(const char *str)
{
	size_t	count;
	size_t	i;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (str[i] == ' ' && !is_quote(str[i - 1]))
			count++;
		i++;
	}
	return (count + 1);
}

/**
 * Allocates memory and copies a substring of a given string.
 *
 * @param str     The source string from which to copy.
 * @param length  The length of the substring to copy.
 * @return A newly allocated string containing the copied substring.
 *         The caller is responsible for freeing the memory
 *         allocated for the returned string.
 */
static char	*allocate_and_copy(const char *str, size_t length)
{
	char	*result;

	result = ft_calloc(length + 1, sizeof(char));
	if (result == NULL)
	{
		perror("ft_calloc");
		exit(EXIT_FAILURE);
	}
	ft_strlcpy(result, str, length);
	return (result);
}

/**
 * Extracts tokens (words) from a given string separated by spaces,
 * excluding those within quotes, and stores them in an array of
 * strings.
 *
 * @param str     The input string to be tokenized.
 * @param result  An array of strings to store the extracted tokens.
 */
static void	extract_tokens(char *str, char **result)
{
	char	*token_start;
	size_t	token_length;
	size_t	index;
	size_t	i;

	i = 0;
	token_length = 0;
	index = 0;
	token_start = str;
	while (str[i] != '\0')
	{
		if ((str[i] == ' ' && !is_quote(str[i - 1])) || str[i + 1] == '\0')
		{
			if (token_length > 0)
			{
				result[index++] = allocate_and_copy(token_start, token_length);
				token_length = 0;
			}
			token_start = &str[i + 1];
		}
		else
			token_length++;
		i++;
	}
	result[index] = NULL;
}

/**
 * Splits a given string into an array of strings, each representing a
 * token (word) separated by spaces, excluding those within quotes.
 *
 * @param str The input string to be split.
 * @return An array of strings representing the tokens.
 *         The last element of the array is set to NULL.
 *         The caller is responsible for freeing the memory allocated
 *         for the array and its strings.
 */
char	**split_string_by_space(char *str)
{
	char	**result;
	size_t	token_count;

	token_count = count_tokens(str);
	result = ft_calloc(token_count + 2, sizeof(char *));
	if (result == NULL)
	{
		perror("ft_calloc");
		exit(EXIT_FAILURE);
	}
	extract_tokens(str, result);
	return (result);
}
