/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_substr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 10:09:48 by fsuomins          #+#    #+#             */
/*   Updated: 2023/07/03 14:08:13 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void t_substr(void)
{
	char** stringArray = NULL;
    int arraySize = 0;
    int counter = 1;
    
    printf("> Testing: %s\n", __FILE__);
    
    // Test case 1: Substring within the string
    const char *str1 = "Hello, World!";
    char *result1 = ft_substr(str1, 7, 5);
    assert(strcmp(result1, "World") == 0);
    free(result1);

    // Test case 2: Substring starting from the beginning of the string
    const char *str2 = "Hello, World!";
    char *result2 = ft_substr(str2, 0, 5);
    assert(strcmp(result2, "Hello") == 0);
    free(result2);

    // Test case 3: Substring with length exceeding the available characters
    const char *str3 = "Hello, World!";
    char *result3 = ft_substr(str3, 7, 20);
    assert(strcmp(result3, "World!") == 0);
    free(result3);

    // Test case 4: Substring starting from a position beyond the string length
    const char *str4 = "Hello, World!";
    char *result4 = ft_substr(str4, 15, 5);
    assert(result4 == NULL);

    // Test case 5: Empty string
    const char *str5 = "";
    char *result5 = ft_substr(str5, 0, 5);
    assert(result5 == NULL);
    
    if (arraySize != 0)
	printf("\n%d", arraySize);
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
