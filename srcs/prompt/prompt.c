/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqueiroz <aqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 10:51:42 by fsuomins          #+#    #+#             */
/*   Updated: 2023/09/02 12:39:17 by aqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static char	*print_prompt(void)
{
	char	*pwd;
	char	*home;
	char	*tmp;
	char	*user;
	char	result[1024];

	pwd = getcwd(NULL, 0);
	home = getenv("HOME");
	if (home && pwd && !ft_strncmp(pwd, home, ft_strlen(home)))
	{
		tmp = ft_strjoin("~", pwd + ft_strlen(home));
		free(pwd);
		pwd = tmp;
	}
	user = getenv("USER");
	*result = '\0';
	ft_strlcat(result, "\033[1;31m", ft_strlen("\033[1;31m") + 1);
	ft_strlcat(result, user, ft_strlen(result) + ft_strlen(user) + 1);
	ft_strlcat(result, "\033[0m", ft_strlen(result) + ft_strlen("\033[0m")
		+ 1);
	ft_strlcat(result, ":", ft_strlen(result) + 2);
	ft_strlcat(result, "\033[1;34m", ft_strlen(result) + ft_strlen("\033[1;34m")
		+ 1);
	ft_strlcat(result, pwd, ft_strlen(result) + ft_strlen(pwd) + 1);
	ft_strlcat(result, "\033[0m", ft_strlen(result) + ft_strlen("\033[0m") + 1);
	ft_strlcat(result, "$ ", ft_strlen(result) + 3);
	free(pwd);
	return (ft_strdup(result));
}

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
