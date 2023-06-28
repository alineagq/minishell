/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 16:27:53 by fsuomins          #+#    #+#             */
/*   Updated: 2023/06/28 16:29:31 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void	push_str(char ***array, int *size, const char *string)
{
	(*size)++;
	*array = realloc(*array, sizeof(char *) * (*size));
	(*array)[*size - 1] = malloc(strlen(string) + 1);
	strcpy((*array)[*size - 1], string);
}
