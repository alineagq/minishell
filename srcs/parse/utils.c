/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 23:24:22 by fsuomins          #+#    #+#             */
/*   Updated: 2023/08/14 23:56:23 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	str_is_command(char *str)
{
	return (strcmp(str, "|") == 0 || strcmp(str, ";") == 0 || \
		strcmp(str, "<") == 0 || strcmp(str, ">") == 0 || \
		strcmp(str, "<<") == 0 || strcmp(str, ">>") == 0);
}

void	free_t_cmd(t_cmd *list)
{
	t_cmd	*temp;

	while (list)
	{
		temp = list;
		list = list->next;
		free(temp->cmd);
		free(temp->argv);
		free(temp);
	}
}