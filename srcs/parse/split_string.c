/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 23:44:21 by fsuomins          #+#    #+#             */
/*   Updated: 2023/08/09 23:58:19 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int    is_quote(char c)
{
    return c == '\'' || c == '"';
}

char** split_string_by_space(char* str) {
    char** result = malloc(sizeof(char*) * (strlen(str) + 1));
    char* token = strtok(str, " ");
    int i = 0;

    while (token != NULL) {
        result[i] = malloc(strlen(token) + 1);
        strcpy(result[i], token);
        token = strtok(NULL, " ");
        i++;
    }
    result[i] = NULL; // Null-terminate the array

    return result;
}

void print_char_array(char **arr) {
    while (*arr) {
        printf("%s\n", *arr);
        arr++;
    }
}

void free_char_array(char **arr) {
    char **temp = arr;
    while (*temp) {
        free(*temp);
        temp++;
    }
    free(arr);
}
