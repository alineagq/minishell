/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_var.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 00:55:09 by fsuomins          #+#    #+#             */
/*   Updated: 2023/08/18 23:19:56 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static char	*update_token(t_config *data, char *var_name, char *var_head)
{
	char	*value;
	char	*part1;
	char	*final_str;
	void	*temp;

	temp = data->tokens->value;
	value = get_env_value(data->env, var_name);
	if (!value)
		part1 = ft_strdup(data->tokens->value);
	else
		part1 = ft_strjoin(data->tokens->value, value);
	final_str = ft_strjoin(part1, var_head + 1 + ft_strlen(var_name));
	free(value);
	free(part1);
	free(temp);
	return (final_str);
}

static void	if_variable(char *var_head, t_config *data)
{
	char	*var_name;

	var_name = get_env_value(data->env, var_head);
	data->tokens->value = update_token(data, var_name, var_head);
	free(var_name);
}

void	expand_variables(t_config *data)
{
	char		*var_head;
	t_tokens	*head;

	head = data->tokens;
	while (data->tokens)
	{
		if (data->tokens->value[0] == '\'')
		{
			data->tokens = data->tokens->next;
			continue ;
		}
		var_head = find_variable(data->tokens->value);
		if (var_head)
			if_variable(var_head, data);
		else
			data->tokens = data->tokens->next;
	}
	data->tokens = head;
}
