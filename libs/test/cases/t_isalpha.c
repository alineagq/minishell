/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_isalpha.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqueiroz <aqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 18:39:59 by aqueiroz          #+#    #+#             */
/*   Updated: 2023/07/21 23:20:02 by aqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../files/test.h"

void	t_isalpha( void)
{
	printf("Testing: %s\n", strrchr(__FILE__, '/') + 1);
    init_report();
	// Test uppercase letters
    assert(ft_isalpha('A') == 1);
    assert(ft_isalpha('B') == 1);
    assert(ft_isalpha('Z') == 1);

    // Test lowercase letters
    assert(ft_isalpha('a') == 1);
    assert(ft_isalpha('b') == 1);
    assert(ft_isalpha('z') == 1);

    // Test non-alphabetic characters
    assert(ft_isalpha('0') == 0);
    assert(ft_isalpha('9') == 0);
    assert(ft_isalpha('$') == 0);
    assert(ft_isalpha('@') == 0);
    assert(ft_isalpha(' ') == 0);
    assert(ft_isalpha('\n') == 0);

    // Test out-of-range characters
    assert(ft_isalpha(200) == 0);
    assert(ft_isalpha(-50) == 0);
	report();
}
