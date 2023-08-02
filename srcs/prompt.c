/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 10:27:06 by fsuomins          #+#    #+#             */
/*   Updated: 2023/08/02 20:45:09 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*read_line(void)
{
	char	*str;

	str = readline("minishell$ ");
	if (str == NULL)
	{
		write(STDOUT_FILENO, "exit\n", 5);
		clean_up();
		exit(EXIT_SUCCESS);
	}
	if (*str)
		add_history(str);
	else
	{
		free(str);
		str = NULL;
	}
	return (str);
}
