/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_strtrim.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 14:49:13 by fsuomins          #+#    #+#             */
/*   Updated: 2023/07/03 15:06:00 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void t_strtrim(void)
{
    char** stringArray = NULL;
    int arraySize = 0;
    int counter = 1;
	
    printf("> Testing: %s\n", __FILE__);
    
    // Test case 1: Trim leading and trailing characters
    const char *s1 = "  Hello, World!  ";
    const char *set1 = " ";
    char *result1 = ft_strtrim(s1, set1);
    assert(strcmp(result1, "Hello, World!") == 0);
    free(result1);

    // Test case 2: Trim leading and trailing characters
    const char *s2 = "===Testing===";
    const char *set2 = "=";
    char *result2 = ft_strtrim(s2, set2);
    assert(strcmp(result2, "Testing") == 0);
    free(result2);

    // Test case 3: Trim all characters
    const char *s3 = "..........";
    const char *set3 = ".";
    char *result3 = ft_strtrim(s3, set3);
    assert(*result3 == '\0');

    // Test case 4: Empty string
    const char *s4 = "";
    const char *set4 = " ";
    char *result4 = ft_strtrim(s4, set4);
    assert(*result4 == '\0');

    // Test case 5: NULL string
    const char *s5 = "Test";
    const char *set5 = NULL;
    char *result5 = ft_strtrim(s5, set5);
    assert(result5 == NULL);

    const char *s6 = NULL;
    const char *set6 = " ";
    char *result6 = ft_strtrim(s6, set6);
    assert(result6 == NULL);

    const char *s7 = NULL;
    const char *set7 = NULL;
    char *result7 = ft_strtrim(s7, set7);
    assert(result7 == NULL);

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
