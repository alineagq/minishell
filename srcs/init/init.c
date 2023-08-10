/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 10:09:21 by fsuomins          #+#    #+#             */
/*   Updated: 2023/08/09 17:30:08 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
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
	t_config	*data;

	data = get_data();
	set_signal();
	data->interactive_mode = 1;
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
