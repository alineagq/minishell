/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqueiroz <aqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by                   #+#    #+#             */
/*   Updated: 2023/06/10 15:34:00 by aqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../libft.h"

int ft_isalnum(int is_a_alnum)
{
    if (ft_isalpha(is_a_alnum) || ft_isdigit(is_a_alnum))
        return (1);
    return (0);
}
