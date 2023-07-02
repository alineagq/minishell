/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_atoi.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 12:44:53 by fsuomins          #+#    #+#             */
/*   Updated: 2023/07/01 21:04:22 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void t_atoi(void)
{
    char** stringArray = NULL;
    int arraySize = 0;
    int counter = 1;
	
    printf("> Testing: %s\n", __FILE__);
    
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

    if (arraySize != 0)
        printf("\n");
    for (int i = 0; i < arraySize; i++) {
        printf("\033[0mError %d: %s\n", i + 1, stringArray[i]);
    }

    // Free the memory allocated for the strings
    for (int i = 0; i < arraySize; i++) {
        free(stringArray[i]);
    }
    // Free the memory allocated for the array
    free(stringArray);
    printf("\n");
}