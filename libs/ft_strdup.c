/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqueiroz <aqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 21:57:46 by fsuomins          #+#    #+#             */
/*   Updated: 2023/07/21 21:17:06 by aqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
