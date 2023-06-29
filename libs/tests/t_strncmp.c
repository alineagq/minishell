/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_strncmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 16:07:56 by fsuomins          #+#    #+#             */
/*   Updated: 2023/06/29 20:04:48 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void t_strncmp(void)
{
	char** stringArray = NULL;
    int arraySize = 0;
    int counter = 1;
	
    printf("> Testing: %s\n", __FILE__);

 
    // Test case 1: Comparing equal strings
    char str1[] = "Hello, World!";
    char str2[] = "Hello, World!";
    int n1 = 13;
    int result1 = ft_strncmp(str1, str2, n1);
    assert(result1 == 0);

 
    // Test case 2: Comparing strings with different lengths
    char str3[] = "Hello, World!";
    char str4[] = "Hello";
    int n2 = 5;
    int result2 = ft_strncmp(str3, str4, n2);
    assert(result2 == 0);
	
    // Test case 3: Comparing strings with different characters
    char str5[] = "Hello";
    char str6[] = "Hella";
    int n3 = 5;
    int result3 = ft_strncmp(str5, str6, n3);
    assert(result3 > 0);

    // Test case 4: Comparing strings with different characters up to n
    char str7[] = "Hello, World!";
    char str8[] = "Helli, World!";
    int n4 = 5;
    int result4 = ft_strncmp(str7, str8, n4);
    assert(result4 > 0);

    // Test case 5: Comparing strings with different characters after n
    char str9[] = "Hello, World!";
    char str10[] = "Hella, World!";
    int n5 = 5;
    int result5 = ft_strncmp(str9, str10, n5);
    assert(result5 > 0);


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
