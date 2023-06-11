/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 19:49:09 by fsuomins          #+#    #+#             */
/*   Updated: 2023/06/10 19:49:16 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_isalnum(int is_a_alnum)
{
	if (ft_isalpha(is_a_alnum) || ft_isdigit(is_a_alnum))
		return (1);
	return (0);
}
