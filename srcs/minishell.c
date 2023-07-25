/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 09:32:18 by aqueiroz          #+#    #+#             */
/*   Updated: 2023/07/25 12:41:17 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	clean_up(void)
{
	pid_t	result;

	result = 0;
	while ((result > 0 || result == -1) && errno == EINTR)
	{
		result = waitpid(-1, NULL, WNOHANG);
	}
}

char	*read_line(void)
{
	char	*str;

	str = readline("minishell$ ");
	if (!*str)
		return (NULL);
	if (*str)
		add_history(str);
	else
	{
		free(str);
		return (NULL);
	}
	return (str);
}

void	init_shell(int argc, char **argv)
{
	(void)argv;
	if (argc != 1)
		exit (0);
	set_signal();
}

int	main(int argc, char **argv, char **environ)
{
	char	*line;

	init_shell(argc, argv);
	while (1)
	{
		line = read_line();
		if (!line)
		{
			write(1, "exit\n", 6);
			free(line);
			clean_up();
			exit(EXIT_SUCCESS);
		}
		free(line);
	}
	return (0);
}
