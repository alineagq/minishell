/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 00:12:17 by viferrei          #+#    #+#             */
/*   Updated: 2023/08/25 21:10:17 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/minishell.h"

int	equal_found(char *str, t_config *data)
{
	if (!*str)
		return (0);
	while (*str)
	{
		if (*str == '=')
			return (1);
		else if (!is_variable(*str))
		{
			ft_putstr_fd(" not a valid identifier\n", 2);
			data->exit_code = 1;
			return (0);
		}
		str++;
	}
	return (0);
}

int	var_exists(char *arg, t_env_list *env)
{
	t_env_list	*head;
	char		*var_name;

	head = env;
	var_name = get_var_name(arg);
	while (head)
	{
		if (ft_strncmp (head->key, var_name, ft_strlen(var_name)))
		{
			free(var_name);
			return (1);
		}
		head = head->next;
	}
	free(var_name);
	return (0);
}

void	replace_var(char *arg, t_env_list *env)
{
	t_env_list	*head;
	char		*old_value;
	char		*var_name;

	head = env;
	var_name = get_var_name(arg);
	while (head)
	{
		if (ft_strncmp (head->key, var_name, ft_strlen(var_name)))
		{
			old_value = head->value;
			head->value = ft_strdup(arg);
			free(old_value);
		}
		head = head->next;
	}
	free(var_name);
}

void	set_variable(char *arg, t_config *data)
{
	t_env_list	*head;

	head = data->env;
	while (head->next)
		head = head->next;
	if (var_exists(arg, data->env))
		replace_var(arg, data->env);
	else
	{
		head->next = ft_calloc(1, sizeof(t_env_list));
		head = head->next;
		head->value = ft_strdup(arg);
	}
}

int has_letter(const char *str) {
    while (*str && *str != '=') {
        if (!isalpha(*str)) {
            return 1;
        }
        str++;
    }
    return 0;
}

int	builtin_export(char	**args, t_com *com, t_config *data)
{
	char		*key;
	char		*value;
	int			valid_input;

	valid_input = 0;
	if (!args[1])
	{
		print_export_list(data->env);
		return (data->exit_code);
	}
	args++;
	while (*args)
	{
		if (has_letter(*args) || ((ft_strlen(*args) < 3) && !valid_input))
		{
			ft_putstr_fd(" not a valid identifier\n", 2);
			data->exit_code = 1;
			return (data->exit_code);
		}
		if (equal_found(*args, data))
		{
			key = ft_strtok(*args, "=");
			value = ft_strtok(NULL, "=");
			set_env(&data->env, key, value);
			free_char_array(com->envp);
			com->envp = tok_envp(data->env);
			valid_input = 1;
		}
		(args)++;
	}
	return (data->exit_code);
}
