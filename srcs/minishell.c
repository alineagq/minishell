/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 09:32:18 by aqueiroz          #+#    #+#             */
/*   Updated: 2023/07/28 10:30:28 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	main(int argc, char **argv)
{
	char	*line;

	init_shell(argc, argv);
	set_signal();
	while (1)
	{
		line = read_line();
		if (line == NULL)
		{
			write(1, "exit\n", 5);
			free(line);
			clean_up();
			exit(EXIT_SUCCESS);
		}
		free(line);
	}
	return (0);
}
