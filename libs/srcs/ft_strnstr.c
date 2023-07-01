/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 02:32:24 by fsuomins          #+#    #+#             */
/*   Updated: 2023/07/01 12:22:25 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	const char	*h;
	const char	*n;

	while (*haystack && len--)
	{

		h = haystack;
		n = needle;

		while (*h && *n && *h == *n && len--)
		{
			h++;
			n++;
		}

		if (*n == '\0')
			return ((char *)haystack);

		haystack++;
		len++;
	}

	return (NULL);
}
