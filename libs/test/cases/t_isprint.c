/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_isprint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqueiroz <aqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 09:36:19 by aqueiroz          #+#    #+#             */
/*   Updated: 2023/07/21 23:20:02 by aqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../files/test.h"

void t_isprint(void)
{
	printf("Testing: %s\n", strrchr(__FILE__, '/') + 1);
    init_report();

    // Test cases
    assert(ft_isprint(65) == 1);
    assert(ft_isprint(0) == 0);
    assert(ft_isprint(126) == 1);
    assert(ft_isprint(127) == 0);
    assert(ft_isprint(31) == 0);
    
    // Additional test cases
    assert(ft_isprint(32) == 1);
    assert(ft_isprint(97) == 1);
    assert(ft_isprint(125) == 1);
    assert(ft_isprint(128) == 0);
    assert(ft_isprint(-1) == 0);

    report();
}
