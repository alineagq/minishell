/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_toupper.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 15:54:41 by fsuomins          #+#    #+#             */
/*   Updated: 2023/06/29 18:19:51 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void t_toupper(void)
{
	char** stringArray = NULL;
    int arraySize = 0;
    int counter = 1;
	
    printf("> Testing: %s\n", __FILE__);

	// Test case 1: Lowercase letter 'a'
    assert(ft_toupper('a') == 'A');

    // Test case 2: Lowercase letter 'z'
    assert(ft_toupper('z') == 'Z');

    // Test case 3: Uppercase letter 'A'
    assert(ft_toupper('A') == 'A');

    // Test case 4: Uppercase letter 'Z'
    assert(ft_toupper('Z') == 'Z');

    // Test case 5: Digit '0'
    assert(ft_toupper('0') == '0');

    // Test case 6: Digit '9'
    assert(ft_toupper('9') == '9');

    // Test case 7: Special character '$'
    assert(ft_toupper('$') == '$');

    // Test case 8: Special character '%'
    assert(ft_toupper('%') == '%');

    // Test case 9: Null character '\0'
    assert(ft_toupper('\0') == '\0');

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