/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_strlen.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 20:30:51 by fsuomins          #+#    #+#             */
/*   Updated: 2023/06/28 16:41:31 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void t_strlen(void)
{
	char** stringArray = NULL;
    int arraySize = 0;
    int counter = 1;
	
    printf("> Testing: %s\n", __FILE__);

    // Test cases
    assert(ft_strlen("") == 0);
    assert(ft_strlen("Hello, world!") == 13);
    assert(ft_strlen("Lorem ipsum dolor sit amet") == 26);
    assert(ft_strlen("1234567890") == 10);
    assert(ft_strlen("This is a test") == 14);

    // Additional test cases
    assert(ft_strlen("123") == 3);
    assert(ft_strlen("abcdefghijklmnopqrstuvwxyz") == 26);
    assert(ft_strlen("0123456789") == 10);
    assert(ft_strlen("Hello\tWorld\n") == 12);
    assert(ft_strlen(NULL) == 0);

    // Compare with strlen function from string.h
    assert(ft_strlen("Hello") == strlen("Hello"));
    assert(ft_strlen("Hello, world!") == strlen("Hello, world!"));
    assert(ft_strlen("Lorem ipsum dolor sit amet") == strlen("Lorem ipsum dolor sit amet"));

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
