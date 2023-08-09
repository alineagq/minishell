/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 09:32:18 by aqueiroz          #+#    #+#             */
/*   Updated: 2023/08/04 20:24:29 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

#define BUFFER_SIZE 64
#define TOKEN_DELIMITERS " \t\r\n\a"
#define CMD_LIST "env exit echo ls pwd export cd unset |"

char** tokenize_line(char* line) {
    int buffer_size = BUFFER_SIZE;
    int position = 0;
    char** tokens = malloc(buffer_size * sizeof(char*));
    char* token;

    if (!tokens) {
        fprintf(stderr, "Allocation error\n");
        exit(EXIT_FAILURE);
    }

    token = strtok(line, TOKEN_DELIMITERS);
    while (token != NULL) {
        tokens[position] = token;
        position++;

        if (position >= buffer_size) {
            buffer_size += BUFFER_SIZE;
            tokens = realloc(tokens, buffer_size * sizeof(char*));
            if (!tokens) {
                fprintf(stderr, "Allocation error\n");
                exit(EXIT_FAILURE);
            }
        }

        token = strtok(NULL, TOKEN_DELIMITERS);
    }
    tokens[position] = NULL;

    return tokens;
}

void print_tokens(char** tokens) {
    for (int i = 0; tokens[i] != NULL; i++) {
        printf("%s\n", tokens[i]);
    }
}

int	main(void)
{
	char		*line;
	t_config	*config;
	char		**tokens;

	init_shell();
	config = get_data();
	while (1)
	{
		line = read_line();
		if (line == NULL)
			continue ;
		tokens = tokenize_line(line);
		print_tokens(tokens);
		free(line);
	}
	return (0);
}
