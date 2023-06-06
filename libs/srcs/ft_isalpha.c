/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br     +#+  +:+       +#+        */
/*   By: fsuomins <fsuomins@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 11:47:37 by aqueiroz          #+#    #+#             */
/*   Updated: 2023/06/04 19:02:03 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int ft_isalpha(int c)
{
    return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

/* THIS FUNCTION is ... I 


if you want try ascii using decimal: (c_is_a_alpha >= 97  ||  c_is_a_alpha 
<= 122), "is the same thing! ;-) */