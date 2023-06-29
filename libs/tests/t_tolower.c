/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_tolower.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 15:43:53 by fsuomins          #+#    #+#             */
/*   Updated: 2023/06/29 18:16:19 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void t_tolower(void)
{
	char** stringArray = NULL;
    int arraySize = 0;
    int counter = 1;
	
    printf("> Testing: %s\n", __FILE__);

	    // Test case 1: Uppercase letter 'A'
    assert(ft_tolower('A') == 'a');

    // Test case 2: Uppercase letter 'Z'
    assert(ft_tolower('Z') == 'z');

    // Test case 3: Lowercase letter 'a'
    assert(ft_tolower('a') == 'a');

    // Test case 4: Lowercase letter 'z'
    assert(ft_tolower('z') == 'z');

    // Test case 5: Digit '0'
    assert(ft_tolower('0') == '0');

    // Test case 6: Digit '9'
    assert(ft_tolower('9') == '9');

    // Test case 7: Special character '$'
    assert(ft_tolower('$') == '$');

    // Test case 8: Special character '%'
    assert(ft_tolower('%') == '%');

    // Test case 9: Null character '\0'
    assert(ft_tolower('\0') == '\0');

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