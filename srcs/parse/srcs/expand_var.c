/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_var.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 00:55:09 by fsuomins          #+#    #+#             */
/*   Updated: 2023/08/20 16:37:31 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

// int get_last_uppercase_index(char *str)
// {
//     int i;
//     int length;
//     int last_uppercase_index;

//     length = strlen(str);
//     last_uppercase_index = -1;
//     i = 0;
//     while (i < length)
//     {
//         if (isupper(str[i]))
//             last_uppercase_index = i;
//         i++;
//     }
//     return last_uppercase_index;
// }

// static char	*update_token(t_config *data, char *var_name)
// {
// 	char	*value;
// 	char	*part1;
// 	char	*final_str;
// 	void	*temp;

// 	temp = data->tokens->value;
// 	value = var_name;
// 	if (!value)
// 		part1 = ft_strdup(data->tokens->value);
// 	else
// 		part1 = value;
// 	final_str = ft_strjoin(part1, temp + get_last_uppercase_index(temp) + 1);
// 	free(part1);
// 	free(temp);
// 	return (final_str);
// }

// static char	*get_substring_until_last_uppercase(char *str)
// {
// 	int		i;
// 	int		length;
// 	int		last_uppercase_index;
// 	char	*result;

// 	length = ft_strlen(str);
// 	last_uppercase_index = -1;
// 	i = 0;
// 	while (i < length)
// 	{
// 		if (ft_isupper(str[i]))
// 			last_uppercase_index = i;
// 		i++;
// 	}
// 	if (last_uppercase_index == -1)
// 		return (ft_strdup(str));
// 	result = (char *)malloc((last_uppercase_index + 2) * sizeof(char));
// 	ft_strlcpy(result, str, last_uppercase_index + 2);
// 	return (result);
// }

// static void	if_variable(char *var_head, t_config *data)
// {
// 	char	*var_name;

// 	var_name = get_env_value(data->env, ++var_head);
// 	data->tokens->value = update_token(data, var_name);
// }

void replace_variables(char *input_string, t_env_list *env_data) {
    char *placeholder = input_string;
    while ((placeholder = strchr(placeholder, '$')) != NULL) {
        // Find the end of the variable name
        char *var_end = placeholder + 1;
        while (*var_end && (*var_end != ' ' && *var_end != '\t' && *var_end != '\n' && *var_end != '\0') && *var_end != '\'' && *var_end != '\"') {
            var_end++;
        }

        // Extract the variable name
        char var_name[100]; // Adjust the size as needed
        strncpy(var_name, placeholder + 1, var_end - placeholder - 1);
        var_name[var_end - placeholder - 1] = '\0';
	
        char *var_value = get_env_value(env_data, var_name);
        if (var_value != NULL) {
            // Create a new string with the replacement
            char *replacement = ft_strjoin(var_value, placeholder + (var_end - placeholder));
            if (replacement != NULL) {
                strcpy(placeholder, replacement);
                free(replacement);
            }

            // Move the placeholder to the end of the replacement
            placeholder += strlen(var_value);
        } else {
            // Move to the next character after the variable name
            placeholder = var_end;
        }
    }
}


void expand_variables(t_config *data) {
    t_tokens *head = data->tokens;
    while (data->tokens) {
        if (data->tokens->value[0] == '\'') {
            data->tokens = data->tokens->next;
            continue;
        }
        char *var_head = find_variable(data->tokens->value);
        if (var_head) {
            replace_variables(data->tokens->value, data->env);
        }
        data->tokens = data->tokens->next;
    }
    data->tokens = head;
}
