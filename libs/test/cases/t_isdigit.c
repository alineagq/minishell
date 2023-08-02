/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_isdigit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqueiroz <aqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by                   #+#    #+#             */
/*   Updated: 2023/07/21 23:20:02 by aqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../files/test.h"

void t_isdigit(void)
{
	printf("Testing: %s\n", strrchr(__FILE__, '/') + 1);
    init_report();

    // Test digits
    assert(ft_isdigit('0') == 1);
    assert(ft_isdigit('1') == 1);
    assert(ft_isdigit('9') == 1);

    // Test non-digit characters
    assert(ft_isdigit('A') == 0);
    assert(ft_isdigit('B') == 0);
    assert(ft_isdigit('z') == 0);
    assert(ft_isdigit('$') == 0);
    assert(ft_isdigit('@') == 0);
    assert(ft_isdigit(' ') == 0);
    assert(ft_isdigit('\n') == 0);

    // Test out-of-range characters
    assert(ft_isdigit(200) == 0);
    assert(ft_isdigit(-50) == 0);

    report();
}
