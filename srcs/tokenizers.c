/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 22:29:44 by fsuomins          #+#    #+#             */
/*   Updated: 2023/07/25 22:37:48 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	**tokenize(char *input)
{
    int buffer_size = 64;
    char **tokens = (char **)malloc(buffer_size * sizeof(char *));
    if (!tokens)
    {
        fprintf(stderr, "Memory allocation error\n");
        exit(EXIT_FAILURE);
    }

    char *token;
    char *delimiters = " \t\r\n\a";
    int token_index = 0;
    int in_single_quotes = 0;
    int in_double_quotes = 0;

    token = strtok(input, delimiters);
    while (token != NULL)
{
    // Check for unclosed double quotes
    int double_quote_count = 0;
    for (int i = 0; i < strlen(token); i++)
    {
        if (token[i] == '"')
            double_quote_count++;
    }

    if (double_quote_count % 2 != 0 && !in_single_quotes) // Check only if not already in single quotes
    {
        fprintf(stderr, "Unclosed double quotes\n");
        free(tokens);
        return NULL;
    }

    // Check for unclosed single quotes
    int single_quote_count = 0;
    for (int i = 0; i < strlen(token); i++)
    {
        if (token[i] == '\'')
            single_quote_count++;
    }

    if (single_quote_count % 2 != 0 && !in_double_quotes) // Check only if not already in double quotes
    {
        fprintf(stderr, "Unclosed single quotes\n");
        free(tokens);
        return NULL;
    }

    // Check for single quotes and handle meta-characters inside them
    if (token[0] == '\'')
    {
        in_single_quotes = 1;
        memmove(token, token + 1, strlen(token)); // Remove the starting single quote
    }

    if (in_single_quotes)
    {
        if (token[strlen(token) - 1] == '\'')
        {
            in_single_quotes = 0;
            token[strlen(token) - 1] = '\0'; // Remove the ending single quote
        }
    }

    // Check for double quotes and handle meta-characters inside them (except $)
    if (token[0] == '"')
    {
        in_double_quotes = 1;
        memmove(token, token + 1, strlen(token)); // Remove the starting double quote
    }

    if (in_double_quotes)
    {
        for (int i = 0; i < strlen(token); i++)
        {
            if (token[i] == '\\' && token[i + 1] != '$')
            {
                // Remove the backslash unless it's before a dollar sign
                memmove(token + i, token + i + 1, strlen(token) - i);
            }
        }

        if (token[strlen(token) - 1] == '"')
        {
            in_double_quotes = 0;
            token[strlen(token) - 1] = '\0'; // Remove the ending double quote
        }
    }

    tokens[token_index] = token;
    token_index++;

    // Check if we need to allocate more memory for tokens
    if (token_index >= buffer_size)
    {
        buffer_size *= 2;
        tokens = realloc(tokens, buffer_size * sizeof(char *));
        if (!tokens)
        {
            fprintf(stderr, "Memory allocation error\n");
            exit(EXIT_FAILURE);
        }
    }

    token = strtok(NULL, delimiters);
}

    tokens[token_index] = NULL;
    return tokens;
}

char *expand_environment_variable(char *variable)
{
    char *value = getenv(variable + 1); // Skip the leading $

    if (value == NULL)
    {
        fprintf(stderr, "Environment variable not found: %s\n", variable);
        return variable; // Return the original variable if not found
    }

    return value;
}
