/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spaces.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 14:45:24 by fsuomins          #+#    #+#             */
/*   Updated: 2023/08/09 23:29:23 by fsuomins         ###   ########.fr       */
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
		if (i != 0 && is_delimiter(input[i]) && (input[i] != input[i - 1]) \
				&& !isspace(input[i - 1]))
			result[size++] = ' ';
		result[size++] = input[i];
		if (i != len - 1 && is_delimiter(input[i]) && input[i] != input[i + 1])
			result[size++] = ' ';
		i++;
	}
	result[size] = '\0';
	return (result);
}
