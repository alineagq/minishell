/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_strdup.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 22:05:21 by fsuomins          #+#    #+#             */
/*   Updated: 2023/07/02 10:56:23 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void    t_strdup(void)
{
    char** stringArray = NULL;
    int arraySize = 0;
    int counter = 1;
	
    printf("> Testing: %s\n", __FILE__);

    // Test case 1: Non-empty string
    const char *str1 = "Hello, World!";
    char *result1 = ft_strdup(str1);
    assert(strcmp(result1, str1) == 0);
    free(result1);

    // Test case 2: Empty string
    const char *str2 = "";
    char *result2 = ft_strdup(str2);
    assert(strcmp(result2, str2) == 0);
    free(result2);

    // Test case 3: String with special characters
    const char *str3 = "Testing special characters: !@#$%^&*()";
    char *result3 = ft_strdup(str3);
    assert(strcmp(result3, str3) == 0);
    free(result3);

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