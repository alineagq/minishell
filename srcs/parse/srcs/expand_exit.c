/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_exit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 14:50:50 by fsuomins          #+#    #+#             */
/*   Updated: 2023/08/24 10:21:31 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

static void	free_mouli(void *a, void *b)
{
	free(a);
	free(b);
	a = NULL;
	b = NULL;
}

char	*find_exit_code(char *str)
{
	while (*str)
	{
		if (*str == '$' && str[1] == '?')
			return (str);
		str++;
	}
	return (NULL);
}

static char	*update_token_exit_code(char *str, char *exit_code, char *var_head)
{
	char	*part1;
	char	*final_str;

	part1 = ft_strjoin(str, exit_code);
	final_str = ft_strjoin(part1, var_head + 2);
	free(part1);
	return (final_str);
}

void	expand_exit_code(t_config *data)
{
	char		*value_head;
	char		*exit_str;
	char		*current;
	t_tokens	*head;

	head = data->tokens;
	while (head)
	{
		if (*head->value == '\'')
		{
			head = head->next;
			continue ;
		}
		value_head = find_exit_code(head->value);
		if (value_head)
		{
			*value_head = '\0';
			exit_str = ft_itoa(data->exit_code);
			current = head->value;
			head->value = update_token_exit_code \
				(head->value, exit_str, value_head);
			free_mouli(exit_str, current);
		}
		else
			head = head->next;
	}
}
