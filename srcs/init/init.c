/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 10:09:21 by fsuomins          #+#    #+#             */
/*   Updated: 2023/08/13 21:14:50 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int count_envp(char* envp[]) {
  int count = 0;
  while (envp[count] != NULL) {
    count++;
  }
  return count;
}

static char **copy_envp(char *envp[])
{
  // Allocate memory for the copy of the environment
  int num_env_vars = count_envp(envp);
  char** env_copy = malloc((num_env_vars + 1) * sizeof(char*));

  // Copy and initialize the environment variables
  for (int i = 0; envp[i] != NULL; i++) {
    int var_len = strlen(envp[i]);
    
    // Allocate memory for the variable, including null terminator
    env_copy[i] = malloc((var_len + 1) * sizeof(char));
    
    // Copy the variable and null terminator
    strncpy(env_copy[i], envp[i], var_len);
    env_copy[i][var_len] = '\0';
  }
  
  // Null-terminate the environment variable list
  env_copy[num_env_vars] = NULL;

  return env_copy;
}



/**
 * Initializes the program state.
 * 
 * This function retrieves the program data, sets up the signal handling, and 
 * switches the program into interactive mode. If the current state is INIT,
 * it changes the state to PROMPT.
 * 
 * This function does not take any arguments and does not return a value.
 */
void	init(void)
{
	extern char	**environ;	
	t_config	*data;

	data = get_data();
	set_signal();
	data->env = copy_envp(environ);
	if (data->state == INIT)
		data->state = PROMPT;
}

/**
 * Retrieves a pointer to the program data.
 * 
 * This function provides access to the program data. It uses a static variable 
 * so that the same data is shared across all calls to this function.
 * 
 * This function does not take any arguments.
 * 
 * @return A pointer to the program data.
 */
t_config	*get_data(void)
{
	static t_config	data;

	return (&data);
}
