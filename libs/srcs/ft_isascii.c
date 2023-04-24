/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 16:31:14 by aqueiroz          #+#    #+#             */
/*   Updated: 2023/04/24 20:38:40 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_isascii(int c_is_a_ascii)
{
	if (c_is_a_ascii >= 0 && c_is_a_ascii <= 127)
		return (1);
	return (0);
}
