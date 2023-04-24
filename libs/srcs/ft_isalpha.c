/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 11:47:37 by aqueiroz          #+#    #+#             */
/*   Updated: 2023/04/24 20:37:26 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/* THIS FUNCTION is ... I 


if you want try ascii using decimal: (c_is_a_alpha >= 97  ||  c_is_a_alpha 
<= 122), "is the same thing! ;-) */

int	ft_isalpha(int c_is_a_alpha)
{
	if (c_is_a_alpha >= 'a' && c_is_a_alpha <= 'z')
		return (1);
	else if (c_is_a_alpha >= 'A' && c_is_a_alpha <= 'Z')
		return (1);
	return (0);
}
