/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 19:36:44 by fsuomins          #+#    #+#             */
/*   Updated: 2023/04/28 19:37:05 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_isalpha(int is_a_alpha)
{
	if (is_a_alpha >= 'a' && is_a_alpha <= 'z')
		return (1);
	else if (is_a_alpha >= 'A' && is_a_alpha <= 'Z')
		return (1);
	return (0);
}
