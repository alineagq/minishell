/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 11:47:37 by aqueiroz          #+#    #+#             */
/*   Updated: 2023/04/21 22:48:14 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/* THIS FUNCTION is ... I 


if you want try ascii using decimal: (is_a_alpha >= 97  ||  is_a_alpha 
<= 122), "is the same thing! ;-) */

int	ft_isalpha(int is_a_alpha)
{
	if (is_a_alpha >= 'a' && is_a_alpha <= 'z')
		return (1);
	else if (is_a_alpha >= 'A' && is_a_alpha <= 'Z')
		return (1);
	return (0);
}
