/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_isascii.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqueiroz <aqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by                   #+#    #+#             */
/*   Updated: 2023/07/21 23:20:02 by aqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../files/test.h"

void t_isascii(void)
{
	printf("Testing: %s\n", strrchr(__FILE__, '/') + 1);
    init_report();

    // Test cases
    assert(ft_isascii(65) == 1);
    assert(ft_isascii(0) == 1);
    assert(ft_isascii(127) == 1);
    assert(ft_isascii(128) == 0);
    assert(ft_isascii(-1) == 0);
    
    // Additional test cases
    assert(ft_isascii(32) == 1);
    assert(ft_isascii(97) == 1);
    assert(ft_isascii(126) == 1);
    assert(ft_isascii(129) == 0);
    assert(ft_isascii(-128) == 0);

    report();
}
