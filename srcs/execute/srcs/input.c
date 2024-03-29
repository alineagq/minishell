/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 02:52:05 by coder             #+#    #+#             */
/*   Updated: 2023/08/19 19:25:34 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

static int	tok_count_inputs(t_tokens *arg_temp)
{
	t_tokens	*temp;
	int			ret;

	ret = 0;
	temp = arg_temp;
	if (temp && temp->type == OPTOKEN)
		temp = temp->next;
	while (temp && temp->type != OPTOKEN)
	{
		if (temp->type == REDTOKEN)
		{
			if (!ft_strcmp("<", temp->value))
				ret++;
			else if (!ft_strcmp("<<", temp->value))
				ret++;
		}
		temp = temp->next;
	}
	return (ret);
}

static void	tok_fill_inlist(t_reds *self, t_tokens *tokens)
{
	if (tokens && tokens->type == OPTOKEN)
		tokens = tokens->next;
	while (tokens && self && tokens->type != OPTOKEN)
	{
		if (tokens->type == REDTOKEN)
		{
			if (!ft_strcmp("<", tokens->value))
			{
				self->type = INFILE;
				self->target = ft_strdup(tokens->next->value);
				self = self->next;
			}
			if (!ft_strcmp("<<", tokens->value))
			{
				self->type = HEREDOC;
				self->target = ft_strdup(tokens->next->value);
				self = self->next;
			}
		}
		tokens = tokens->next;
	}
}

t_reds	*tok_input(t_config *data)
{
	t_tokens	*temp;
	t_reds		*self;
	int			count;

	temp = iterate_to_tok_index(data);
	count = tok_count_inputs(temp);
	self = create_red_list(count);
	if (self)
		tok_fill_inlist(self, temp);
	return (self);
}
