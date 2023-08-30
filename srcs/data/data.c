/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 18:25:06 by fsuomins          #+#    #+#             */
/*   Updated: 2023/08/30 18:28:52 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

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
