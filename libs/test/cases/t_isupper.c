/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_isupper.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqueiroz <aqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 00:32:06 by aqueiroz          #+#    #+#             */
/*   Updated: 2023/07/21 23:20:02 by aqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../files/test.h"

void	t_isupper(void)
{
	printf("Testing: %s\n", strrchr(__FILE__, '/') + 1);
    init_report();
	// Test uppercase letters
    assert(ft_isupper('A') == 1);
    assert(ft_isupper('B') == 1);
    assert(ft_isupper('Z') == 1);

    // Test lowercase letters
    assert(ft_isupper('a') == 0);
    assert(ft_isupper('b') == 0);
    assert(ft_isupper('z') == 0);

    // Test non-alphabetic characters
    assert(ft_isupper('0') == 0);
    assert(ft_isupper('9') == 0);
    assert(ft_isupper('$') == 0);
    assert(ft_isupper('@') == 0);
    assert(ft_isupper(' ') == 0);
    assert(ft_isupper('\n') == 0);

    // Test out-of-range characters
    assert(ft_isupper(200) == 0);
    assert(ft_isupper(-50) == 0);
	report();
}
