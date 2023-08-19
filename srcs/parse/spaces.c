/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spaces.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 14:45:24 by fsuomins          #+#    #+#             */
/*   Updated: 2023/08/18 23:35:39 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	need_space_before(char *buffer, int op_index, char operator)
{
	int	flag;

	flag = 0;
	if (op_index == 0)
		return (0);
	op_index--;
	while (op_index)
	{
		if (buffer[op_index] == operator)
		{
			if (flag)
				return (1);
			flag++;
		}
		if (flag && buffer[op_index - 1] != operator)
			return (0);
		else if (buffer[op_index] != ' ')
			return (1);
		else if (buffer[op_index] == ' ')
			return (0);
		op_index--;
	}
	return (0);
}

static int	need_space_after(char *buffer, int op_index, char operator)
{
	int	flag;

	flag = 0;
	op_index++;
	while (op_index)
	{
		if (buffer[op_index] == operator)
		{
			if (flag == 2)
				return (1);
			flag++;
		}
		if (flag && buffer[op_index + 1] != operator)
			return (0);
		else if (buffer[op_index] != ' ' && buffer[op_index] != 0)
			return (1);
		else if (buffer[op_index] == ' ' || buffer[op_index] == 0)
			return (0);
		op_index++;
	}
	return (0);
}

static char	*add_space_before_index(char *buffer, int index)
{
	char	*ret;
	int		i;
	int		j;

	i = 0;
	j = 0;
	ret = malloc (sizeof (char) * (ft_strlen(buffer) + 2));
	while (buffer[i])
	{
		if (i == index)
		{
			ret[j] = ' ';
			j++;
		}
		ret[j] = buffer[i];
		i++;
		j++;
	}
	ret[j] = 0;
	return (ret);
}

static char	*recursively_does_black_magic(char *buffer, int i, t_config *data)
{
	char	*temp;

	if (need_space_before(buffer, i, buffer[i]))
	{
		temp = add_space_before_index(buffer, i);
		buffer = safe_free(buffer);
		buffer = temp;
		temp = NULL;
		data->set_buffer_to_null = 1;
		return (add_spaces(buffer, data));
	}
	if (need_space_after(buffer, i, buffer[i]))
	{
		temp = add_space_before_index(buffer, i + 1);
		buffer = safe_free(buffer);
		buffer = temp;
		temp = NULL;
		data->set_buffer_to_null = 1;
		return (add_spaces(buffer, data));
	}
	return (buffer);
}

char	*add_spaces(char *buffer, t_config *data)
{
	int		i;
	int		sin_quote;
	int		dou_quote;

	i = 0;
	sin_quote = 0;
	dou_quote = 0;
	while (buffer[i])
	{
		if (buffer[i] == '\'' && (dou_quote % 2 == 0))
			sin_quote++;
		if (buffer[i] == '\"' && (sin_quote % 2 == 0))
			dou_quote++;
		if ((dou_quote % 2) || (sin_quote % 2))
		{
			i++;
			continue ;
		}
		if (is_delimiter(buffer[i]))
			buffer = recursively_does_black_magic(buffer, i, data);
		i++;
	}
	return (buffer);
}
