/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_memcpy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 19:14:43 by fsuomins          #+#    #+#             */
/*   Updated: 2023/06/30 02:21:49 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void t_memcpy(void)
{
    char** stringArray = NULL;
    int arraySize = 0;
    int counter = 1;

	printf("> Testing: %s\n", __FILE__);

    // Test case 1: Copying a string to a destination buffer
    char src1[] = "Hello, World!";
    char dest1[20];
    ft_memcpy(dest1, src1, strlen(src1) + 1);
    assert(strcmp(dest1, src1) == 0);

    // Test case 2: Copying an empty string to a destination buffer
    char src2[] = "";
    char dest2[10];
    ft_memcpy(dest2, src2, strlen(src2) + 1);
    assert(strcmp(dest2, src2) == 0);

    // Test case 3: Copying a portion of a string to a destination buffer
    char src3[] = "Hello, World!";
    char dest3[10];
    ft_memcpy(dest3, src3 + 7, strlen(src3) - 6);
    assert(strcmp(dest3, "World!") == 0);

    // Test case 4: Copying to overlapping memory regions
  
	char src4[] = "Hello, World!";
    char dest4[20];
    ft_memcpy(dest4, src4, strlen(src4) + 1);
    ft_memcpy(dest4 + 7, dest4, strlen(dest4) - 6);
    assert(strcmp(dest4, "Hello, Hello, ") == 0);


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
