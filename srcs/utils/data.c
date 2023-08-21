/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 16:06:48 by fsuomins          #+#    #+#             */
/*   Updated: 2023/08/21 17:20:17 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_config	*get_data(void)
{
	static t_config	data;

	return (&data);
}

static void	close_inherited_fds(void)
{
	int	fd;

	fd = 3;
	while (fd < 1024)
	{
		close(fd);
		fd++;
	}
}

void	*destroy_token_list(t_config *data)
{
	t_tokens	*freeme;

	if (!data->tokens)
		return (NULL);
	while (data->tokens)
	{
		freeme = data->tokens;
		safe_free(freeme->value);
		freeme->value = NULL;
		data->tokens = data->tokens->next;
		safe_free(freeme);
		freeme = NULL;
	}
	return (NULL);
}

void	clear_data(t_config	*data)
{
	data->tok_index = 0;
	if (data->state == PROMPT)
		free_tokens(data->tokens);
	if (data->state == PARSE)
	{
		if (data->set_buffer_to_null)
			data->prompt = NULL;
		free(data->parse);
		free_char_array(data->raw_tokens);
	}
	if (data->state == EXIT)
	{
		if (data->oldpwd)
			free(data->oldpwd);
		clear_env(data);
	}
	close_inherited_fds();
}
