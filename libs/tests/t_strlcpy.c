/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_strlcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 10:06:26 by fsuomins          #+#    #+#             */
/*   Updated: 2023/06/29 18:03:56 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void	t_strlcpy(void)
{
	char** stringArray = NULL;
    int arraySize = 0;
    int counter = 1;
	
    printf("> Testing: %s\n", __FILE__);

	char dest1[10];
	char dest2[10];
	char dest3[10];
	char dest4[10];
	char dest5[10];

	// Test case 1: Source string fits entirely within destination buffer
	assert(ft_strlcpy(dest1, "Hello", sizeof(dest1)) == 5);
	assert(strcmp(dest1, "Hello") == 0);

	// Test case 2: Source string larger than destination buffer
	assert(ft_strlcpy(dest2, "Hello, World!", sizeof(dest2)) == 13);
	assert(strcmp(dest2, "Hello, Wo") == 0);

	// Test case 3: Empty source string
	assert(ft_strlcpy(dest3, "", sizeof(dest3)) == 0);
	assert(strcmp(dest3, "") == 0);

	// Test case 4: Destination buffer size is 0
	assert(ft_strlcpy(dest4, "Hello", 0) == 5);

	// Test case 5: Source string fits entirely within destination buffer,
	// but destination buffer is smaller than the source string
	assert(ft_strlcpy(dest5, "Hello, World!", 5) == 13);
	assert(strcmp(dest5, "Hell\0") == 0);

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
