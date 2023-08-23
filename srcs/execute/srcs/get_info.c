/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 00:27:26 by fsuomins          #+#    #+#             */
/*   Updated: 2023/08/23 14:26:30 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

static int	tok_from_pipe(t_config *data)
{
	t_tokens	*temp;

	temp = iterate_to_tok_index(data);
	if (temp && temp->type == OPTOKEN)
		return (1);
	return (0);
}

static int	tok_to_pipe(t_config *data)
{
	t_tokens	*temp;

	temp = iterate_to_tok_index(data);
	if (temp && temp->type == OPTOKEN)
	{
		temp = temp->next;
		data->tok_index++;
	}
	while (temp)
	{
		if (temp->type == OPTOKEN)
		{
			return (1);
		}
		data->tok_index++;
		temp = temp->next;
	}
	return (0);
}

static int	last_tok_index(t_config *data)
{
	t_tokens	*temp;
	int			ret;

	ret = 0;
	temp = data->tokens;
	while (temp)
	{
		ret = temp->index;
		temp = temp->next;
	}
	return (ret);
}

static int	check_for_errtokens(t_config *data, t_com *self)
{
	t_tokens	*temp;
	char		*str;
	char		token[2];

	temp = data->tokens;
	while (temp)
	{
		if (temp->type == ERRTOKEN)
		{
			self->block_exec = 1;
			token[0] = temp->value[0];
			token[1] = '\0';
			str = ft_strjoin(" syntax error near unexpected token `", token);
			self->error_to_print = ft_strjoin(str, "'");
			free(str);
			data->exit_code = 2;
			return (1);
		}
		temp = temp->next;
	}
	return (0);
}

t_com	*get_exec_info(t_config *data)
{
	t_com	*self;

	if (data->tok_index > last_tok_index(data))
		return (NULL);
	self = ft_calloc(1, sizeof(t_com));
	if (check_for_errtokens(data, self))
		return (self);
	self->receives_from_pipe = tok_from_pipe(data);
	self->command = tok_command(data, self);
	self->args = tok_args(data);
	self->red_in = tok_input(data);
	self->red_out = tok_output(data);
	self->envp = tok_envp(data->env);
	self->sends_to_pipe = tok_to_pipe(data);
	return (self);
}
