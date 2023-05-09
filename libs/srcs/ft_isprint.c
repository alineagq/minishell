/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 20:12:41 by fsuomins          #+#    #+#             */
/*   Updated: 2023/05/09 20:00:25 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int    ft_isprint(int c_is_printable)
{
    if (c_is_printable >= 32 || c_is_printable <= 126)
        return (1);
    return (0);
}
