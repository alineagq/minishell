/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 20:11:40 by fsuomins          #+#    #+#             */
/*   Updated: 2023/06/10 19:45:20 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_bzero(void *s, size_t n)
{
	char	*ptr;
	char	*end;

	ptr = (char *)s;
	end = ptr + n;
	while (ptr < end)
		*ptr++ = 0;
}

/*
The bzero() function erases the data in the n bytes of the memory starting at the
 location pointed to by s, by writing zeros (bytes containing '\0') to that area.

A função bzero() apaga os dados nos n bytes da memória começando no
 localização apontada por s, escrevendo zeros (bytes contendo '\0') nessa área.
*/