/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 22:28:10 by fsuomins          #+#    #+#             */
/*   Updated: 2023/04/28 19:37:20 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_isdigit(int is_a_digit)
{
	if (is_a_digit >= '0' && is_a_digit <= '9')
		return (1);
	return (0);
}

int ft_isalnum(int is_a_alnum)
{
    if (ft_isalpha(is_a_alnum) || ft_isdigit(is_a_alnum))
        return (1);
    return (0);
}
