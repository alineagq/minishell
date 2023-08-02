/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_strlen.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqueiroz <aqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 20:30:51 by fsuomins          #+#    #+#             */
/*   Updated: 2023/07/21 23:20:02 by aqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../files/test.h"

void t_strlen(void)
{
	printf("Testing: %s\n", strrchr(__FILE__, '/') + 1);
    init_report();

    // Test cases
    assert(ft_strlen("") == 0);
    assert(ft_strlen("Hello, world!") == 13);
    assert(ft_strlen("Lorem ipsum dolor sit amet") == 26);
    assert(ft_strlen("1234567890") == 10);
    assert(ft_strlen("This is a test") == 14);

    // Additional test cases
    assert(ft_strlen("123") == 3);
    assert(ft_strlen("abcdefghijklmnopqrstuvwxyz") == 26);
    assert(ft_strlen("0123456789") == 10);
    assert(ft_strlen("Hello\tWorld\n") == 12);
    assert(ft_strlen(NULL) == 0);

    // Compare with strlen function from string.h
    assert(ft_strlen("Hello") == strlen("Hello"));
    assert(ft_strlen("Hello, world!") == strlen("Hello, world!"));
    assert(ft_strlen("Lorem ipsum dolor sit amet") == strlen("Lorem ipsum dolor sit amet"));

    report();
}
