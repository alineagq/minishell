/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 11:13:28 by fsuomins          #+#    #+#             */
/*   Updated: 2023/08/25 22:24:48 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void remove_empty_or_whitespace_nodes(t_tokens **head)
{
    t_tokens *current = *head;
    
    while (current != NULL)
    {
        t_tokens *next = current->next;
        
        if (current->value == NULL || strspn(current->value, " ") == strlen(current->value))
        {
            if (current->prev)
                current->prev->next = current->next;
            if (current->next)
                current->next->prev = current->prev;
            if (current == *head)
                *head = current->next;
            
            // Libera a memória alocada para o nó
            free(current->value);
            free(current);
        }
        
        current = next;
    }
}

void	expand_tilde(t_config *data)
{
	t_tokens *current = data->tokens;
	char *home_dir = getenv("HOME");
	char *new_value;

	while (current != NULL)
	{
		if (current->type == WORDTOKEN && current->value[0] == '~')
		{
			if (home_dir == NULL)
				new_value = ft_strdup(current->value);
			else
				new_value = ft_strjoin(home_dir, current->value + 1);
			free(current->value);
			current->value = new_value;
		}
		current = current->next;
	}
}

int is_valid_file(char *filename) {
    if(access(filename, F_OK) != -1) {
        return 1; // file exists and is accessible
    } else {
        return 0; // file does not exist or is not accessible
    }
}


void remove_invalid_redirections(t_tokens **head) {
    t_tokens	*current = *head;
    t_tokens	*prev = NULL;
    t_tokens	*next_next;
	int			type_is = current->type;

    while (current != NULL && current->next != NULL) {
        if (type_is == 1 && current->type == REDTOKEN && is_valid_file(current->next->value)) {
            next_next = current->next->next;

            // if the current node is not the head
            if (prev != NULL) {
                prev->next = next_next;
            } else { // if the current node is the head
                *head = next_next;
            }

            // if the next node is not the tail
            if (next_next != NULL) {
                next_next->prev = prev;
            }

            free(current->next);
            free(current);
            
            // update the current node to the next valid node
            current = next_next;
        } else {
            prev = current;
            current = current->next;
        }
    }
}



void	remove_end_spaces(t_config *data)
{
	char		*str;

	str = ft_strtrim(data->prompt, " ");
	if (str)
	{
		free(data->prompt);
		data->prompt = str;
	}
	if (*str == '#')
	{
		data->state = PROMPT;
		return ;
	}
}

void	parse(void)
{
	t_config	*data;

	data = get_data();
	remove_end_spaces(data);
	data->parse = add_spaces(data->prompt, data);
	data->raw_tokens = create_tokens_args(data->parse, ' ');
	create_tokens(data);
	expand_exit_code(data);
	expand_variables(data);
	remove_empty_or_whitespace_nodes(&data->tokens);
	categorize_tokens(data->tokens);
	remove_quotes_from_tokens(data->tokens);
	remove_invalid_redirections(&data->tokens);
	categorize_tokens(data->tokens);
	expand_tilde(data);
	if (data->tokens == NULL)
		data->state = PROMPT;
	clear_data(data);
	if (data->state == PARSE)
		data->state = EXECUTE;
}
