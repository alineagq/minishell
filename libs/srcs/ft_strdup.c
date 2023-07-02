/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 21:57:46 by fsuomins          #+#    #+#             */
/*   Updated: 2023/07/01 22:04:29 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strdup(const char *str)
{
	size_t	len;
	char	*new_str;

	len = strlen(str) + 1;
	new_str = (char *) malloc(len * sizeof(char));
	if (new_str != NULL)
		ft_memcpy(new_str, str, len * sizeof(char));
	return (new_str);
}
