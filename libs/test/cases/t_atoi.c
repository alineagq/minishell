/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_atoi.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqueiroz <aqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 20:29:28 by aqueiroz          #+#    #+#             */
/*   Updated: 2023/07/21 23:20:06 by aqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../files/test.h"

void	t_atoi(void)
{
	printf("Testing: %s\n", strrchr(__FILE__, '/') + 1);
    init_report();
    
    // Test case 1: Positive integer
    const char *str1 = "123";
    int result1 = ft_atoi(str1);
    assert(result1 == 123);

    // Test case 2: Negative integer
    const char *str2 = "-456";
    int result2 = ft_atoi(str2);
    assert(result2 == -456);

    // Test case 3: Leading whitespace
    const char *str3 = "    789";
    int result3 = ft_atoi(str3);
    assert(result3 == 789);

    // Test case 4: Trailing characters after the number
    const char *str4 = "123abc";
    int result4 = ft_atoi(str4);
    assert(result4 == 123);

    // Test case 5: Empty string
    const char *str5 = "";
    int result5 = ft_atoi(str5);
    assert(result5 == 0);

    // Test case 6: Overflow
    const char *str6 = "2147483648";
    int result6 = ft_atoi(str6);
    assert(result6 == -2147483648); // Expected maximum value of INT_MAX

    // Test case 7: Underflow
    const char *str7 = "-2147483649";
    int result7 = ft_atoi(str7);
    assert(result7 == 2147483647); // Expected minimum value of INT_MIN
	report();
}
