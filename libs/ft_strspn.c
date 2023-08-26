/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strspn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 01:36:09 by fsuomins          #+#    #+#             */
/*   Updated: 2023/08/26 01:45:17 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strspn(const char *s, const char *accept)
{
	size_t		count;
	const char	*a;

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
