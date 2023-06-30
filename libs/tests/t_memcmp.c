/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_memcmp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 02:20:34 by fsuomins          #+#    #+#             */
/*   Updated: 2023/06/30 02:26:11 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void t_memcmp(void)
{
	char** stringArray = NULL;
    int arraySize = 0;
    int counter = 1;
	
    printf("> Testing: %s\n", __FILE__);

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