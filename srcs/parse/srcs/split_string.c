/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 23:44:21 by fsuomins          #+#    #+#             */
/*   Updated: 2023/08/19 18:36:59 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	iterate_through_quotes(t_split_shell *this)
{
	char	first_char;

	first_char = this->temp[0];
	if (first_char == '\'' || first_char == '\"')
	{
		if (this->temp[1])
			this->temp++;
		while (this->temp[0] && (this->temp[0] != first_char))
			this->temp++;
		if (this->temp[0] == first_char)
			this->temp++;
	}
}

static int	count_till_quo(char *temp)
{
	char	quote;
	int		count;

	count = 0;
	quote = temp[0];
	while (temp[count] && (temp[count] != quote || !count))
	{
		count++;
	}
	if (temp[count] == quote)
	{
		count++;
	}
	return (count);
}

static int	get_word_size(char *str, char delimiter)
{
	char	*temp;
	int		size;
	int		ret;

	temp = str;
	size = 0;
	ret = 0;
	while (*temp && *temp == delimiter)
		temp++;
	while (*temp && *temp != delimiter)
	{
		if (*temp == '\'' || *temp == '\"')
		{
			size = count_till_quo(temp);
			temp += size;
			ret += size;
		}
		else
		{
			temp++;
			ret ++;
		}
	}
	return (ret);
}

static void	copy_to_split(char *split, t_split_shell *this, int k)
{
	while (k < this->sz)
	{
		split[k] = this->temp[0];
		this->temp++;
		k++;
	}
}

char	**ft_split_shell(char *str, char delimiter)
{
	char			**splits;
	t_split_shell	*this;

	this = ft_calloc (1, sizeof(*this) + 1);
	this->temp = str;
	this->delimiter = delimiter;
	this->string = str;
	count_words(this);
	splits = ft_calloc ((this->words + 1), sizeof(char *));
	this->temp = this->string;
	while (this->i < this->words)
	{
		while (this->temp[0] == this->delimiter)
			this->temp++;
		this->sz = (get_word_size(this->temp, ' '));
		splits[this->i] = ft_calloc (this->sz + 1, 1);
		copy_to_split (splits[this->i], this, 0);
		this->i++;
	}
	this = safe_free(this);
	return (splits);
}
