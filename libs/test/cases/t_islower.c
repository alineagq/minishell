/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_islower.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqueiroz <aqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 00:28:01 by aqueiroz          #+#    #+#             */
/*   Updated: 2023/07/21 23:20:02 by aqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../files/test.h"

void	t_islower(void)
{
	printf("Testing: %s\n", strrchr(__FILE__, '/') + 1);
    init_report();
	// Test uppercase letters
    assert(ft_islower('A') == 0);
    assert(ft_islower('B') == 0);
    assert(ft_islower('Z') == 0);

    // Test lowercase letters
    assert(ft_islower('a') == 1);
    assert(ft_islower('b') == 1);
    assert(ft_islower('z') == 1);

    // Test non-alphabetic characters
    assert(ft_islower('0') == 0);
    assert(ft_islower('9') == 0);
    assert(ft_islower('$') == 0);
    assert(ft_islower('@') == 0);
    assert(ft_islower(' ') == 0);
    assert(ft_islower('\n') == 0);

    // Test out-of-range characters
    assert(ft_islower(200) == 0);
    assert(ft_islower(-50) == 0);
	report();
}
