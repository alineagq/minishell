/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_strmapi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 22:27:35 by fsuomins          #+#    #+#             */
/*   Updated: 2023/07/03 22:45:48 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

// Helper function to apply the mapping function
static char mappingFunction(unsigned int index, char c)
{
	(void)index; 
    // Example mapping function: convert lowercase letters to uppercase
    if (c >= 'a' && c <= 'z')
        return c - ('a' - 'A');
    return c;
}

void t_strmapi(void)
{
    char** stringArray = NULL;
    int arraySize = 0;
    int counter = 1;

    printf("> Testing: %s\n", __FILE__);

    // Test case 1: Map lowercase to uppercase
    char str1[] = "Hello, World!";
    char* result1 = ft_strmapi(str1, mappingFunction);
    assert(strcmp(result1, "HELLO, WORLD!") == 0);
    free(result1);

    // Test case 2: Map every character to itself
    char str2[] = "abcdefghijklmnopqrstuvwxyz";
    char* result2 = ft_strmapi(str2, mappingFunction);
    assert(strcmp(result2, "ABCDEFGHIJKLMNOPQRSTUVWXYZ") == 0);
    free(result2);

    // Test case 3: Empty string
    char str3[] = "";
    char* result3 = ft_strmapi(str3, mappingFunction);
    assert(strcmp(result3, "") == 0);
    free(result3);

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
