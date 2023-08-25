/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 11:13:28 by fsuomins          #+#    #+#             */
/*   Updated: 2023/08/25 15:45:52 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	check_for_open_quotes(char *prompt)
{
	int	i;
	int	single_quotes;
	int	double_quotes;

	i = 0;
	single_quotes = 0;
	double_quotes = 0;
	while (prompt[i])
	{
		if (prompt[i] == '\'' && (double_quotes % 2 == 0))
			single_quotes++;
		if (prompt[i] == '\"' && (single_quotes % 2 == 0))
			double_quotes++;
		i++;
	}
	return ((single_quotes % 2) + (double_quotes % 2));
}

static int	is_only_space(char *str)
{
	if (str && !*str)
		return (0);
	while (str)
	{
		if (!*str)
			return (1);
		if (*str != ' ')
			return (0);
		str++;
	}
	return (1);
}

void remove_empty_or_whitespace_nodes(t_tokens **head)
{
    t_tokens *current = *head;
    
    while (current != NULL)
    {
        t_tokens *next = current->next;
        
        if (current->value == NULL || strspn(current->value, " ") == strlen(current->value))
        {
            // Remove o nó da lista
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

void	parse(void)
{
	t_config	*data;
	char		*str;

	data = get_data();
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
	if (check_for_open_quotes(data->prompt))
	{
		printf("Check for open quotes.\n");
		data->exit_code = 2;
		data->state = PROMPT;
	}
	else if (!is_only_space(data->prompt))
	{
		data->parse = add_spaces(data->prompt, data);
		data->raw_tokens = create_tokens_args(data->parse, ' ');
		create_tokens(data);
		expand_exit_code(data);
		expand_variables(data);
		categorize_tokens(data->tokens);
		remove_quotes_from_tokens(data->tokens);
		remove_empty_or_whitespace_nodes(&data->tokens);
		remove_invalid_redirections(&data->tokens);
		expand_tilde(data);
		if (data->tokens == NULL)
			data->state = PROMPT;
	}
	else
	{
		data->state = PROMPT;
		if (!data->set_buffer_to_null)
			free(data->prompt);
	}
	clear_data(data);
	close_inherited_fds();
	if (data->state == PARSE)
		data->state = EXECUTE;
}
