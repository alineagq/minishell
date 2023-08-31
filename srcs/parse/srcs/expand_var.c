/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_var.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 00:55:09 by fsuomins          #+#    #+#             */
/*   Updated: 2023/08/26 19:14:43 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

static char	*find_var_name(char *str)
{
	char	var_name[100];
	int		i;

	i = 0;
	while (str[i] && (ft_isalnum(str[i]) || str[i] == '_'))
	{
		var_name[i] = str[i];
		i++;
	}
	var_name[i] = '\0';
	return (ft_strdup(var_name));
}

char	*replace_variables(char *input_string, t_env *env_data)
{
	char	*var_head;
	char	*var_name;
	char	*var_value;
	char	*final_str;
	char	*temp_str;

	final_str = NULL;
	var_head = find_variable(input_string);
	if (!var_head)
		return (NULL);
	while (var_head)
	{
		var_name = find_var_name(++var_head);
		var_value = get_env_value(env_data, var_name);
		final_str = ft_substr(input_string, 0, var_head - input_string - 1);
		temp_str = ft_strjoin(final_str, var_value);
		free(final_str);
		final_str = ft_strjoin(temp_str, var_head + ft_strlen(var_name));
		free(temp_str);
		var_head = find_variable(final_str);
		free(var_name);
	}
	return (final_str);
}

void	expand_variables(t_config *data)
{
	t_tokens	*head;
	char		*expanded_value;

	head = data->tokens;
	while (data->tokens)
	{
		if (*data->tokens->value == '\'')
		{
			data->tokens = data->tokens->next;
			continue ;
		}
		expanded_value = replace_variables(data->tokens->value, data->env);
		if (expanded_value)
		{
			free(data->tokens->value);
			data->tokens->value = expanded_value;
		}
		data->tokens = data->tokens->next;
	}
	data->tokens = head;
}
