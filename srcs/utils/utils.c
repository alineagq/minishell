/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 16:06:48 by fsuomins          #+#    #+#             */
/*   Updated: 2023/08/17 01:44:31 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/**
 * Retrieves a pointer to the static configuration data structure.
 * This function returns a pointer to a statically allocated `t_config`
 * structure,
 * which is used to store program configuration and state information.
 * 
 * @return A pointer to the `t_config` data structure.
 */
t_config	*get_data(void)
{
	static t_config	data;

	return (&data);
}

/**
 * Free a dynamically allocated array of strings, including the strings
 * themselves.
 *
 * This function releases the memory used by an array of strings, where
 * each string is individually allocated, and then frees the memory of
 * the array itself.
 *
 * @param arr A pointer to an array of strings to be freed. The array
 * is terminated by a NULL pointer.
 */
void	free_char_array(char **arr)
{
	int		i;

	if (arr == NULL)
		return ;
	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}

void free_raw_tokens(t_config *config)
{
    int i;

    if (config->raw_tokens != NULL)
    {
        for (i = 0; config->raw_tokens[i] != NULL; i++)
        {
            free(config->raw_tokens[i]);
        }
        free(config->raw_tokens);
        config->raw_tokens = NULL;
    }
}

void	free_env(t_config *data)
{
	int	i;

	i = 0;
	if (data->env != NULL)
	{
		while (data->env[i] != NULL)
			free(data->env[i++]);
		free(data->env);
	}
}

void free_parse(t_config *config)
{
    if (config->parse)
    {
        free(config->parse);
        config->parse = NULL;
    }
}

void free_prompt(t_config *config)
{
    if (config->prompt)
    {
        free(config->prompt);
        config->prompt = NULL;
    }
}

void	clear_tokens(t_config *data)
{
	t_cmd	*current;
	t_cmd	*next;

	current = data->tokens;
	while (current != NULL)
	{
		next = current->next;
		free(current->cmd);
		free(current->argv);
		free(current);
		current = next;
	}
	data->tokens = NULL;
}

void	clear_data(t_config	*data)
{
	if (data->state == PARSE || data->state == EXIT)
		free_prompt(data);
		free_parse(data);
		free_raw_tokens(data);
	if (data->state == EXECUTE || data->state == EXIT)
	{
		clear_tokens(data);
	}
	if (data->state == EXIT)
		free_env(data);
}
