/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 20:03:05 by fsuomins          #+#    #+#             */
/*   Updated: 2023/08/03 20:10:06 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

size_t	ft_strspn(const char *s, const char *accept)
{
	const char	*a;
	size_t		count;

	count = 0;
	while (*s)
	{
		a = accept;
		while (*a)
		{
			if (*s == *a)
			{
				count++;
				break ;
			}
			a++;
		}
		if (!*a)
			break ;
		s++;
	}
	return (count);
}
