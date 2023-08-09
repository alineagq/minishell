/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spaces.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 14:45:24 by fsuomins          #+#    #+#             */
/*   Updated: 2023/08/08 21:07:02 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	is_delimiter(char c)
{
	return (c == '|' || c == '>' || c == '<');
}


char *add_spaces(char *input) {
    size_t len = strlen(input);
    size_t size = 0;
    char *result = (char *)malloc(sizeof(char) * (len * 2 + 1));

    if (!result) {
        perror("Memory allocation failed");
        return NULL;
    }

    for (size_t i = 0; i < len; i++) {
        if (i != 0 && is_delimiter(input[i]) && (input[i] != input[i - 1]) && !isspace(input[i - 1])) {
            result[size++] = ' ';
        }
        result[size++] = input[i];
        if (i != len - 1 && is_delimiter(input[i]) && input[i] != input[i + 1]) {
            result[size++] = ' ';
        }
    }
    result[size] = '\0';

    return result;
}