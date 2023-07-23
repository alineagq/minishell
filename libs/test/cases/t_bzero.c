/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_bzero.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqueiroz <aqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 20:45:47 by aqueiroz          #+#    #+#             */
/*   Updated: 2023/07/22 00:55:24 by aqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../files/test.h"

void	t_bzero(void)
{
	printf("Testing: %s\n", strrchr(__FILE__, '/') + 1);
    init_report();

    char buffer[10];

    // Test case 1: Clearing a non-empty buffer
    strcpy(buffer, "Hello");
    ft_bzero(buffer, 5);
    for (int i = 0; i < 5; i++)
        assert(buffer[i] == 0);

    // Test case 2: Clearing an empty buffer
    memset(buffer, 'A', 10);
    ft_bzero(buffer, 0);
    for (int i = 0; i < 10; i++)
        assert(buffer[i] == 'A');

    // Test case 3: Clearing the entire buffer
    memset(buffer, 'B', 10);
    ft_bzero(buffer, 10);
    for (int i = 0; i < 10; i++)
        assert(buffer[i] == 0);

    // Test case 4: Clearing a buffer partially
    memset(buffer, 'C', 10);
    ft_bzero(buffer + 2, 5);
    assert(buffer[0] == 'C');
    assert(buffer[1] == 'C');
    assert(buffer[2] == 0);
    assert(buffer[3] == 0);
    assert(buffer[4] == 0);
    assert(buffer[5] == 0);
    assert(buffer[6] == 0);
    assert(buffer[7] == 'C');
    assert(buffer[8] == 'C');
    assert(buffer[9] == 'C');

    report();
}
