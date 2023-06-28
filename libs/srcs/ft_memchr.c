/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 17:28:06 by fsuomins          #+#    #+#             */
/*   Updated: 2023/06/28 17:28:48 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			index;

	index = 0;
	while (index < n)
	{
		if (((unsigned char *)s)[index] == (unsigned char) c)
			return ((void *)s + index);
		index++;
	}
	return (NULL);
}
