/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 16:14:05 by aqueiroz          #+#    #+#             */
/*   Updated: 2023/04/24 21:35:58 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
if you want try ascii using decimal: (c_is_a_alpha >= 48  ||  c_is_a_alpha 
<= 57), "is the same thing! ;-) 
*/
int	ft_isdigit(int c_is_a_digit)
{
	if (c_is_a_digit >= '0' && c_is_a_digit <= '9')
		return (1);
	return (0);
}
