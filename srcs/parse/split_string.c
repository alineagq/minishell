/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 23:44:21 by fsuomins          #+#    #+#             */
/*   Updated: 2023/08/17 00:45:46 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	extract_tokens(char *str, char **result, size_t token_count)
{
	char	*token;
	int		i;

	i = 0;
	token = strtok(str, " ");
	while (token != NULL && i < token_count - 1)
	{
		result[i++] = ft_strdup(token);
		token = strtok(NULL, " ");
	}

	result[i] = NULL;
}

static int	tokens_size(char *str)
{
	size_t	len;

	len = 0;
	while (str[len] && str[len] != ' ')
		len++;
	return (len);
}

char	**split_string_by_space(char *str)
{
	char	**result;
	size_t	token_count;

	token_count = tokens_size(str);
	// printf("Prompt: %s\n", str);
	// printf("token_count: %zu\n", token_count);
	result = ft_calloc(token_count + 1, sizeof(char *));
	if (result == NULL)
	{
		perror("ft_calloc");
		exit(EXIT_FAILURE);
	}
	extract_tokens(str, result, token_count);
	return (result);
}
