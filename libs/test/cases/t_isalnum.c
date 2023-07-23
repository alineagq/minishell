/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_isalnum.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqueiroz <aqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by                   #+#    #+#             */
/*   Updated: 2023/07/21 23:20:02 by aqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../files/test.h"

void t_isalnum(void)
{
	printf("Testing: %s\n", strrchr(__FILE__, '/') + 1);
    init_report();

    // Test with alphanumeric characters
    assert(ft_isalnum('a') == 1);
    assert(ft_isalnum('A') == 1);
    assert(ft_isalnum('5') == 1);

    // Test with non-alphanumeric characters
    assert(ft_isalnum('$') == 0);
    assert(ft_isalnum('!') == 0);
    assert(ft_isalnum(' ') == 0);

    // Test with special characters
    assert(ft_isalnum('\0') == 0);       // Null character
    assert(ft_isalnum('\n') == 0);       // Newline character
    assert(ft_isalnum('\t') == 0);       // Tab character

    // Test with extended ASCII characters
    assert(ft_isalnum(128) == 0);        // Ç
    assert(ft_isalnum(255) == 0);        // ÿ

    // Test with negative values
    assert(ft_isalnum(-1) == 0);
    assert(ft_isalnum(-128) == 0);

    // Test with maximum positive value
    assert(ft_isalnum(127) == 0);
    report();
}
