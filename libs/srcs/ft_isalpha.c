/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 11:47:37 by aqueiroz          #+#    #+#             */
/*   Updated: 2023/05/10 00:24:07 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_isalpha(int c_is_a_alpha)
{
	if (c_is_a_alpha >= 'a' && c_is_a_alpha <= 'z')
		return (1);
	else if (c_is_a_alpha >= 'A' && c_is_a_alpha <= 'Z')
		return (1);
	return (0);
}

/* THIS FUNCTION is ... I 


if you want try ascii using decimal: (c_is_a_alpha >= 97  ||  c_is_a_alpha 
<= 122), "is the same thing! ;-) */