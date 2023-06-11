/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 10:05:29 by fsuomins          #+#    #+#             */
/*   Updated: 2023/06/11 11:24:05 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t maxlen)
{
	size_t	src_size;

	src_size = ft_strlen(src);
	if (src_size < maxlen)
		ft_memcpy(dst, src, src_size + 1);
	else if (maxlen)
	{
		ft_memcpy(dst, src, maxlen);
		dst[maxlen - 1] = '\0';
	}
	dst[maxlen] = '\0';
	return (src_size);
}
