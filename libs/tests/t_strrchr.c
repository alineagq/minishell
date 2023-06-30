/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_strrchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 14:24:18 by fsuomins          #+#    #+#             */
/*   Updated: 2023/06/30 02:13:22 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void t_strrchr(void)
{
	char** stringArray = NULL;
    int arraySize = 0;
    int counter = 1;
	
    printf("> Testing: %s\n", __FILE__);

    const char *str = "Hello, World!";
    
    // Test case 1: Character 'o' is present in the string
    char *result = ft_strrchr(str, 'o');
    assert(result != NULL);
    assert(*result == 'o');

    // Test case 2: Character 'z' is not present in the string
    char *result2 = ft_strrchr(str, 'z');
    assert(result2 == NULL);

    // Test case 3: Null character '\0' is present in the string
    char *result3 = ft_strrchr(str, '\0');
    assert(result3 != NULL);
    assert(*result3 == '\0');

    // Test case 4: Empty string
    const char *empty_str = "";
    char *result4 = ft_strrchr(empty_str, 'o');
    assert(result4 == NULL);

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