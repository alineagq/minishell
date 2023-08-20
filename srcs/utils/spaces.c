/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 10:01:40 by fsuomins          #+#    #+#             */
/*   Updated: 2023/08/18 10:14:19 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	is_delimiter(char c)
{
	return (c == '>' || c == '<' || c == '|');
}

void	count_words(t_split_shell *this)
{
	this->temp = this->string;
	while (this->temp[0])
	{
		this->words++;
		while (this->temp[0] == this->delimiter)
			this->temp++;
		while (this->temp[0] && (this->temp[0] != this->delimiter))
		{
			if (this->temp[0] == '\'' || this->temp[0] == '\"')
				iterate_through_quotes(this);
			else
				this->temp++;
		}
	}
}
