/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 00:27:26 by fsuomins          #+#    #+#             */
/*   Updated: 2023/08/22 11:19:41 by fsuomins         ###   ########.fr       */
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
	printf("receives_from_pipe: %d\n", self->receives_from_pipe);
	self->command = tok_command(data, self);
	printf("command: %s\n", self->command);
	self->args = tok_args(data);
	printf("args:\n");
	for (int i = 0; self->args[i] != NULL; i++)
	{
		printf("  %s\n", self->args[i]);
	}
	self->red_in = tok_input(data);
	printf("red_in:\n");
	for (t_reds *tmp = self->red_in; tmp != NULL; tmp = tmp->next)
	{
		printf("  type: %d\n", tmp->type);
		printf("  target: %s\n", tmp->target);
	}
	self->red_out = tok_output(data);
	printf("red_out:\n");
	for (t_reds *tmp = self->red_out; tmp != NULL; tmp = tmp->next)
	{
		printf("  type: %d\n", tmp->type);
		printf("  target: %s\n", tmp->target);
	}
	self->envp = tok_envp(data->env);
	// printf("envp:\n");
	// for (int i = 0; self->envp[i] != NULL; i++)
	// {
	// 	printf("  %s\n", self->envp[i]);
	// }
	self->sends_to_pipe = tok_to_pipe(data);
	printf("sends_to_pipe: %d\n", self->sends_to_pipe);
	return (self);
}
