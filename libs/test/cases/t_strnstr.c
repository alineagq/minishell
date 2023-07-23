/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_strnstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqueiroz <aqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 02:34:08 by fsuomins          #+#    #+#             */
/*   Updated: 2023/07/21 23:20:02 by aqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../files/test.h"

void t_strnstr(void)
{
	printf("Testing: %s\n", strrchr(__FILE__, '/') + 1);
    init_report();

    const char *haystack = "Hello, World!";
    const char *needle = "World";

    // Test case 1: Needle is present in the haystack
    char *result1 = ft_strnstr(haystack, needle, strlen(haystack));
    assert(result1 != NULL);
    assert(strcmp(result1, "World!") == 0);

    // Test case 2: Needle is not present in the haystack
    const char *needle2 = "Universe";
    char *result2 = ft_strnstr(haystack, needle2, strlen(haystack));
    assert(result2 == NULL);

    // Test case 3: Empty needle
    const char *empty_needle = "";
    char *result3 = ft_strnstr(haystack, empty_needle, strlen(haystack));
    assert(result3 != NULL);
    assert(strcmp(result3, haystack) == 0);

    // Test case 4: Empty haystack
    const char *empty_haystack = "";
    char *result4 = ft_strnstr(empty_haystack, needle, strlen(empty_haystack));
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