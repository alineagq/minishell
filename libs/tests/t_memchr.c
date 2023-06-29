/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_memchr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 16:48:24 by fsuomins          #+#    #+#             */
/*   Updated: 2023/06/29 15:42:21 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void t_memchr(void)
{
	char** stringArray = NULL;
    int arraySize = 0;
    int counter = 1;
	
    printf("> Testing: %s\n", __FILE__);

    // Test case 1: Searching for a character in a non-empty string
    char str1[] = "Hello, World!";
    int searchChar1 = 'o';
    void* result1 = ft_memchr(str1, searchChar1, strlen(str1));
    assert(result1 != NULL);
    assert(*(char*)result1 == searchChar1);

    // Test case 2: Searching for a character in an empty string
    char str2[] = "";
    int searchChar2 = 'A';
    void* result2 = ft_memchr(str2, searchChar2, strlen(str2));
    assert(result2 == NULL);

    // Test case 3: Searching for a character that is not in the string
    char str3[] = "Hello, World!";
    int searchChar3 = 'Z';
    void* result3 = ft_memchr(str3, searchChar3, strlen(str3));
    assert(result3 == NULL);

    // Test case 4: Searching for a null character in a string
    char str4[] = "Hello, World!";
    int searchChar4 = '\0';
    void* result4 = ft_memchr(str4, searchChar4, strlen(str4) + 1);
    assert(result4 != NULL);
    assert(*(char*)result4 == searchChar4);

    // Test case 5: Searching for a character in a portion of the string
    char str5[] = "Hello, World!";
    int searchChar5 = 'W';
    void* result5 = ft_memchr(str5 + 7, searchChar5, strlen(str5) - 7);
    assert(result5 != NULL);
    assert(*(char*)result5 == searchChar5);

    // Test case 6: Searching for a character in a string with special characters
    char str6[] = "This is a test with \n newline character!";
    int searchChar6 = '\n';
    void* result6 = ft_memchr(str6, searchChar6, strlen(str6));
    assert(result6 != NULL);
    assert(*(char*)result6 == searchChar6);

    // Test case 7: Searching for a character in a string with repeated characters
    char str7[] = "AAAAAAAAAA";
    int searchChar7 = 'A';
    void* result7 = ft_memchr(str7, searchChar7, strlen(str7));
    assert(result7 != NULL);
    assert(*(char*)result7 == searchChar7);


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
