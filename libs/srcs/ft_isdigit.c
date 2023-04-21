/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 16:14:05 by aqueiroz          #+#    #+#             */
/*   Updated: 2023/04/21 22:48:30 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*
if you want try ascii using decimal: (is_a_alpha >= 48  ||  is_a_alpha 
<= 57), "is the same thing! ;-) 
*/
int	ft_isdigit(int is_a_digit)
{
	if (is_a_digit >= '0' && is_a_digit <= '9')
		return (1);
	return (0);
}
