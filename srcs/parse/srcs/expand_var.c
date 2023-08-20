/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_var.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 00:55:09 by fsuomins          #+#    #+#             */
/*   Updated: 2023/08/20 03:34:37 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

int get_last_uppercase_index(char *str)
{
    int i;
    int length;
    int last_uppercase_index;

    length = strlen(str);
    last_uppercase_index = -1;
    i = 0;
    while (i < length)
    {
        if (isupper(str[i]))
            last_uppercase_index = i;
        i++;
    }
    return last_uppercase_index;
}

static char	*update_token(t_config *data, char *var_name)
{
	char	*value;
	char	*part1;
	char	*final_str;
	void	*temp;

	temp = data->tokens->value;
	value = var_name;
	if (!value)
		part1 = ft_strdup(data->tokens->value);
	else
		part1 = value;
	final_str = ft_strjoin(part1, temp + get_last_uppercase_index(temp) + 1);
	free(part1);
	free(temp);
	return (final_str);
}

static char	*get_substring_until_last_uppercase(char *str)
{
	int		i;
	int		length;
	int		last_uppercase_index;
	char	*result;

	length = ft_strlen(str);
	last_uppercase_index = -1;
	i = 0;
	while (i < length)
	{
		if (ft_isupper(str[i]))
			last_uppercase_index = i;
		i++;
	}
	if (last_uppercase_index == -1)
		return (ft_strdup(str));
	result = (char *)malloc((last_uppercase_index + 2) * sizeof(char));
	ft_strlcpy(result, str, last_uppercase_index + 2);
	return (result);
}

static void	if_variable(char *var_head, t_config *data)
{
	char	*var_name;

	var_name = get_env_value(data->env, ++var_head);
	data->tokens->value = update_token(data, var_name);
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
		{
			var_head = get_substring_until_last_uppercase(var_head);
			if_variable(var_head, data);
		}
		data->tokens = data->tokens->next;
	}
	data->tokens = head;
}
