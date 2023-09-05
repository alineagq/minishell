/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 10:51:42 by fsuomins          #+#    #+#             */
/*   Updated: 2023/09/05 10:10:28 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static char	*read_line(t_config *data)
{
	char	*str;
	char	*tmp;

	tmp = print_prompt();
	str = readline(tmp);
	free(tmp);
	if (!str)
	{
		write(STDOUT_FILENO, "exit\n", 5);
		data->exit_code = 0;
		data->state = EXIT;
		return (NULL);
	}
	else
	{
		if (*str)
		{
			add_history(str);
			return (str);
		}
		else
			free(str);
	}
	return (NULL);
}

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

void	validate_prompt(t_config *data)
{
	if (data->prompt)
	{
		if (check_for_open_quotes(data->prompt))
		{
			ft_putstr_fd("minishell: syntax error: unexpected end of file\n",
				2);
			data->exit_code = 2;
		}
		else if (!is_only_space(data->prompt))
		{
			if (data->state == PROMPT)
				data->state = PARSE;
		}
	}
}

void	prompt(void)
{
	t_config	*data;

	data = get_data();
	data->prompt = read_line(data);
	validate_prompt(data);
	if (data->state == PROMPT && data->prompt)
		free(data->prompt);
}
