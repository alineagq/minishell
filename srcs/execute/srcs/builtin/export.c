/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 00:12:17 by viferrei          #+#    #+#             */
/*   Updated: 2023/08/19 20:39:56 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/minishell.h"

// Returns 1 if a '=' is found in the string
int	equal_found(char *str, t_config *data)
{
	char	*head;

	if (!*str)
		return (0);
	head = str;
	while (*str)
	{
		if (*str == '=')
			return (1);
		else if (!is_variable(*str))
		{
			printf("export: '%s': not a valid identifier\n", head);
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

// Adds the variable to the environment list or replaces its value if it's
// already set
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

int	builtin_export(char	**args, t_config *data)
{
	if (!args[1])
	{
		printf("export: forgot something?\n");
		return (data->exit_code);
	}
	args++;
	while (*args)
	{
		if (equal_found(*args, data))
			set_variable(*args, data);
		(args)++;
	}
	return (data->exit_code);
}
