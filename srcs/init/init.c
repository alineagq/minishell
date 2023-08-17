/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 10:09:21 by fsuomins          #+#    #+#             */
/*   Updated: 2023/08/16 17:43:39 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/**
 * Count the number of elements in an array of strings.
 *
 * @param env An array of strings, terminated by a NULL pointer.
 * @return The count of elements in the array.
 */
static int	count_env(char **env)
{
	int	count;

	count = 0;
	while (env[count] != NULL)
		count++;
	return (count);
}

/**
 * Create a copy of an array of strings representing environment variables.
 *
 * This function duplicates an array of strings representing environment
 * variables, creating a new dynamically allocated array.
 * Each string within the original array is duplicated using memory
 * allocation, and the new array is terminated by a NULL pointer.
 * If memory allocation fails during the duplication process, the function
 * ensures proper cleanup.
 *
 * @param env An array of strings, terminated by a NULL pointer,
 * representing environment variables.
 * @return A new dynamically allocated array of strings containing copied
 * environment variables, terminated by a NULL pointer. Returns NULL if 
 *         memory allocation fails.
 *         The caller is responsible for freeing the returned array and
 *         its elements.
 */
static char	**copy_env(char **env)
{
	char	**env_copy;
	int		n_envs;
	int		i;

	i = 0;
	n_envs = count_env(env);
	env_copy = ft_calloc((n_envs + 1), sizeof(char *));
	if (env_copy == NULL)
		return (NULL);
	while (env[i] != NULL)
	{
		env_copy[i] = ft_strdup(env[i]);
		if (env_copy[i] == NULL)
		{
			free_char_array(env_copy);
			return (NULL);
		}
		i++;
	}
	env_copy[i] = NULL;
	return (env_copy);
}

/**
 * Initialize configuration data and environment variables.
 * This function sets up signal handling, creates a copy of the
 * environment variables, and updates the configuration
 * state to PROMPT if no errors ocurrs.
 */
void	init(void)
{
	extern char	**environ;	
	t_config	*data;

	data = get_data();
	set_signal();
	data->env = copy_env(environ);
	if (data->state == INIT)
		data->state = PROMPT;
}
