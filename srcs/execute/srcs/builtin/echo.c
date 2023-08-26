/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 03:55:52 by viferrei          #+#    #+#             */
/*   Updated: 2023/08/26 09:01:08 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/minishell.h"

int	should_skip_newline(char **args)
{
	if (!args[1])
		return (1);
	if (!ft_strcmp(args[1], "-n"))
		return (0);
	return (1);
}

void	print_echo_output(char **args)
{
	int	i;

	i = 1;
	while (args[i])
	{
		printf("%s", args[i]);
		if (args[i + 1])
			printf(" ");
		i++;
	}
	if (args[i])
		printf("%s", args[i]);
}

int	builtin_echo(char **args)
{
	int	newline;

	newline = should_skip_newline(args);
	print_echo_output(args);
	if (newline)
		printf("\n");
	return (0);
}
