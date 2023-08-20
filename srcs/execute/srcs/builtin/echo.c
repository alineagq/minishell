/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 03:55:52 by viferrei          #+#    #+#             */
/*   Updated: 2023/08/20 01:33:14 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/minishell.h"

int	builtin_echo(char **args)
{
	int	newline;
	int	i;

	newline = 1;
	i = 1;
	if (!args[1])
	{
		printf("\n");
		return (0);
	}
	if (!ft_strcmp(args[i], "-n"))
	{
		newline = 0;
		i++;
	}
	while (args[i])
	{
		printf("%s", args[i]);
		if (args[i + 1])
			printf(" ");
		i++;
	}
	if (args[i])
		printf("%s", args[i]);
	if (newline)
		printf("\n");
	return (0);
}
