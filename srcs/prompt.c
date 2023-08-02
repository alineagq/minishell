/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 10:27:06 by fsuomins          #+#    #+#             */
/*   Updated: 2023/07/28 10:33:48 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*read_line(void)
{
	char	*str;

	str = readline("minishell$ ");
	if (str == NULL)
		return (NULL);
	if (*str)
		add_history(str);
	else
	{
		free(str);
		str = NULL;
	}
	return (str);
}
