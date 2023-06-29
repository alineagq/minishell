/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_strlcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 16:03:43 by fsuomins          #+#    #+#             */
/*   Updated: 2023/06/29 19:40:00 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"
#include <string.h>
void	t_strlcat(void)
{
	char** stringArray = NULL;
    int arraySize = 0;
    int counter = 1;
	
    printf("> Testing: %s\n", __FILE__);

	char dest[20] = "Hello";
    const char *src = " World!";
    
    // Test case 1: Destination buffer has enough space for both source and destination strings
    size_t result = ft_strlcat(dest, src, sizeof(dest));
    assert(result == 12);
    assert(strcmp(dest, "Hello World!") == 0);

    // Test case 2: Destination buffer does not have enough space for the entire source string
    char dest2[6] = "Hello";
    size_t result2 = ft_strlcat(dest2, src, sizeof(dest2));
    assert(result2 == 12);
    assert(strcmp(dest2, "Hello") == 0);

    // Test case 3: Empty destination buffer
    char dest3[10] = "";
    size_t result3 = ft_strlcat(dest3, src, sizeof(dest3));
    assert(result3 == 7);
    assert(strcmp(dest3, " World!") == 0);

    // Test case 4: Empty source string
    char dest4[10] = "Hello";
    const char *empty_src = "";
    size_t result4 = ft_strlcat(dest4, empty_src, sizeof(dest4));
    assert(result4 == 5);
    assert(strcmp(dest4, "Hello") == 0);

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