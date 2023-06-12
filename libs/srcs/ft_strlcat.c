/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 16:04:57 by fsuomins          #+#    #+#             */
/*   Updated: 2023/06/12 16:21:51 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	i;
	size_t	res;

	i = 0;
	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (dstsize > dst_len)
	{
		res = (src_len + dst_len);
		while (src[i] && (dst_len + 1) < dstsize)
		{
			dst[dst_len] = ((char *)src)[i];
			i++;
			dst_len++;
		}
		dst[dst_len] = '\0';
	}
	else
	{
		res = src_len + dstsize;
	}
	return (res);
}