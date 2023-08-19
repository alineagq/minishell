/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 14:44:30 by fsuomins          #+#    #+#             */
/*   Updated: 2023/08/18 16:18:22 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	create_tokens(t_config *data)
{
	int			i;
	t_tokens	*self;
	t_tokens	*temp;
	t_tokens	*previous;

	if (!data->raw_tokens || !data->raw_tokens[0])
		data->tokens = NULL;
	else
	{
		i = -1;
		self = ft_calloc(1, sizeof(*self));
		temp = self;
		temp->prev = NULL;
		while (data->raw_tokens[++i])
		{
			temp->value = ft_strdup(data->raw_tokens[i]);
			if (data->raw_tokens[i + 1])
			{
				temp->next = ft_calloc(1, sizeof(*self));
				if (temp->next)
				{
					temp->next->prev = temp;
					temp = temp->next;
				}
			}
		}
		data->tokens = self;
	}
}
