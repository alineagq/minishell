/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_var.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 00:55:09 by fsuomins          #+#    #+#             */
/*   Updated: 2023/08/19 01:09:35 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static char	*get_var_value(char *name, t_env_list *env)
{
	size_t	len;
	char	*str;
	char	*var_value;

	var_value = NULL;
	len = 0;
	while (env)
	{
		str = env->key;
		if (vars_match(str, name))
		{
			var_value = env->value;
			break ;
		}
		env = env->next;
	}
	return (var_value);
}

static char	*update_token(t_config *data, char *var_name, char *var_head)
{
	char	*value;
	char	*part1;
	char	*final_str;
	void	*temp;

	temp = data->tokens->value;
	value = get_var_value(var_name, data->env);
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

	var_name = get_var_name(var_head);
	*var_head = '\0';
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