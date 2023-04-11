/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqueiroz <aqueiroz@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 21:20:25 by fsuomins          #+#    #+#             */
/*   Updated: 2023/04/10 22:56:36 by aqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	tot_size;
	void	*pos;

	tot_size = nmemb * size;
	if (nmemb == 0 || size == 0 || tot_size > INT_MAX)
		return (NULL);
	pos = malloc(tot_size);
	if (pos == NULL)
		return (NULL);
	memset(pos, 0, tot_size);
	return (pos);
}
