/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 11:13:28 by fsuomins          #+#    #+#             */
/*   Updated: 2023/08/25 21:35:17 by fsuomins         ###   ########.fr       */
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

void remove_invalid_redirections(t_tokens **head)
{
    t_tokens *current = *head;

	while (current != NULL)
	{
        t_tokens *next = current->next;
		if (current->type == REDTOKEN && !ft_strcmp(current->value, "<"))
		{
            if (current->prev)
                current->prev->next = current->next;
            if (current->next)
                current->next->prev = current->prev;
            if (current == *head)
                *head = current->next;
            
            free(current->value);
            free(current);
			current = next;
			if (current->prev)
                current->prev->next = current->next;
            if (current->next)
                current->next->prev = current->prev;
            if (current == *head)
                *head = current->next;
            free(current->value);
            free(current);
        }
        current = next;
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
