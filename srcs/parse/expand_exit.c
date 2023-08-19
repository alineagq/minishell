/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_exit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 14:50:50 by fsuomins          #+#    #+#             */
/*   Updated: 2023/08/18 14:52:01 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	free_mouli(void *a, void *b)
{
	free(a);
	free(b);
	a = NULL;
	b = NULL;
}

static char	*find_exit_code(char *str)
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
	char		*v_head;
	char		*exit_str;
	char		*temp;
	t_tokens	*head;

	head = data->tokens;
	while (head)
	{
		if (head->value[0] == '\'')
		{
			head = head->next;
			continue ;
		}
		v_head = find_exit_code(head->value);
		if (v_head)
		{
			*v_head = '\0';
			exit_str = ft_itoa(data->exit_code);
			temp = head->value;
			head->value = update_token_exit_code(head->value, exit_str, v_head);
			free_mouli(exit_str, temp);
		}
		else
			head = head->next;
	}
}
