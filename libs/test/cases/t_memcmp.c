/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_memcmp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqueiroz <aqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 02:20:34 by fsuomins          #+#    #+#             */
/*   Updated: 2023/07/21 23:20:02 by aqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../files/test.h"

void t_memcmp(void)
{
	printf("Testing: %s\n", strrchr(__FILE__, '/') + 1);
    init_report();

    const char *str1 = "Hello";
    const char *str2 = "Hello";
    const char *str3 = "Hellp";
    const char *str4 = "Hellq";
    const char *empty_str1 = "";
    const char *empty_str2 = "";

    // Test case 1: Same memory blocks, equal strings
    int result1 = ft_memcmp(str1, str2, strlen(str1));
    assert(result1 == 0);

    // Test case 2: Same memory blocks, different strings
    int result2 = ft_memcmp(str1, str3, strlen(str1));
    assert(result2 != 0);

    // Test case 3: Different memory blocks, equal strings
    int result3 = ft_memcmp(str3, str4, strlen(str3));
    assert(result3 < 0);

    // Test case 4: Different memory blocks, different strings
    int result4 = ft_memcmp(str1, str4, strlen(str1));
    assert(result4 < 0);

    // Test case 5: Empty memory blocks
    int result5 = ft_memcmp(empty_str1, empty_str2, 0);
    assert(result5 == 0);

    report();
}