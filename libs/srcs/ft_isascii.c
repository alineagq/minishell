/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqueiroz <aqueiroz@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 16:31:14 by aqueiroz          #+#    #+#             */
/*   Updated: 2023/04/21 16:40:21 by aqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isascii(int is_a_ascii)
{
	if (is_a_ascii >= 0 && is_a_ascii <= 127)
		return (1);
	return (0);
}
