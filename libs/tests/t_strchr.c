/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_strchr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 15:06:14 by fsuomins          #+#    #+#             */
/*   Updated: 2023/06/29 19:21:43 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void t_strchr(void)
{
    char** stringArray = NULL;
    int arraySize = 0;
    int counter = 1;

    printf("> Testing: %s\n", __FILE__);

    // Test case 1: Searching for a character that exists in the string
    char str1[] = "Hello, World!";
    char ch1 = 'o';
    char* result1 = ft_strchr(str1, ch1);
    assert(result1 != NULL && *result1 == ch1);

    // Test case 2: Searching for a character that doesn't exist in the string
    char str2[] = "Hello, World!";
    char ch2 = 'z';
    char* result2 = ft_strchr(str2, ch2);
    assert(result2 == NULL);

    // Test case 3: Searching for the null terminator character
    char str3[] = "Hello, World!";
    char ch3 = '\0';
    char* result3 = ft_strchr(str3, ch3);
    assert(result3 != NULL && *result3 == ch3);

    // Test case 4: Searching in an empty string
    char str4[] = "";
    char ch4 = 'a';
    char* result4 = ft_strchr(str4, ch4);
    assert(result4 == NULL);

    // Additional test cases...

    // Print error messages if any
    if (arraySize != 0)
    {
        printf("\n");
        for (int i = 0; i < arraySize; i++)
        {
            printf("\033[0mError %d: %s\n", i + 1, stringArray[i]);
        }
    }

    // Free the memory allocated for the strings
    for (int i = 0; i < arraySize; i++)
    {
        free(stringArray[i]);
    }

    // Free the memory allocated for the array
    free(stringArray);

    printf("\n");
}
