/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_itoa.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 22:19:25 by fsuomins          #+#    #+#             */
/*   Updated: 2023/07/03 22:22:26 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void t_itoa(void)
{
    char** stringArray = NULL;
    int arraySize = 0;
    int counter = 1;

    printf("> Testing: %s\n", __FILE__);

    // Test case 1: Positive number
    int n1 = 12345;
    char* result1 = ft_itoa(n1);
    assert(strcmp(result1, "12345") == 0);
    free(result1);

    // Test case 2: Negative number
    int n2 = -98765;
    char* result2 = ft_itoa(n2);
    assert(strcmp(result2, "-98765") == 0);
    free(result2);

    // Test case 3: Zero
    int n3 = 0;
    char* result3 = ft_itoa(n3);
    assert(strcmp(result3, "0") == 0);
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
