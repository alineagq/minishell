/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 22:28:10 by fsuomins          #+#    #+#             */
/*   Updated: 2023/04/24 20:37:07 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int ft_isalnum(int c_is_a_alnum)
{
    if (ft_isalpha(c_is_a_alnum) || ft_isdigit(c_is_a_alnum))
        return (1);
    return (0);
}
