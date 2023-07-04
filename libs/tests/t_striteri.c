/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_striteri.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 22:36:18 by fsuomins          #+#    #+#             */
/*   Updated: 2023/07/03 22:48:28 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

// Helper function to perform an action on each character
static void actionFunction(unsigned int index, char* c)
{
	(void)index; 
    // Example action function: convert lowercase letters to uppercase
    if (*c >= 'a' && *c <= 'z')
        *c = *c - ('a' - 'A');
}

void t_striteri(void)
{
    char** stringArray = NULL;
    int arraySize = 0;
    int counter = 1;

    printf("> Testing: %s\n", __FILE__);

    // Test case 1: Convert lowercase to uppercase
    char str1[] = "Hello, World!";
    ft_striteri(str1, actionFunction);
    assert(strcmp(str1, "HELLO, WORLD!") == 0);

    // Test case 2: Empty string
    char str2[] = "";
    ft_striteri(str2, actionFunction);
    assert(strcmp(str2, "") == 0);

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
