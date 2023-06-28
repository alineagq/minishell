/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_bzero.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 20:11:13 by fsuomins          #+#    #+#             */
/*   Updated: 2023/06/28 17:09:37 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void	t_bzero(void)
{
	char** stringArray = NULL;
    int arraySize = 0;
    int counter = 1;
	
    printf("> Testing: %s\n", __FILE__);
	
    char buffer[10];

    // Test case 1: Clearing a non-empty buffer
    strcpy(buffer, "Hello");
    ft_bzero(buffer, 5);
    assert(strcmp(buffer, "\0\0\0\0\0") == 0);

    // Test case 2: Clearing an empty buffer
    memset(buffer, 'A', 10);
    ft_bzero(buffer, 0);
    for (int i = 0; i < 10; i++)
        assert(buffer[i] == 'A');

    // Test case 3: Clearing the entire buffer
    memset(buffer, 'B', 10);
    ft_bzero(buffer, 10);
    for (int i = 0; i < 10; i++)
        assert(buffer[i] == 0);

    // Test case 4: Clearing a buffer partially
    memset(buffer, 'C', 10);
    ft_bzero(buffer + 2, 5);
    assert(buffer[0] == 'C');
    assert(buffer[1] == 'C');
    assert(buffer[2] == 0);
    assert(buffer[3] == 0);
    assert(buffer[4] == 0);
    assert(buffer[5] == 0);
    assert(buffer[6] == 0);
    assert(buffer[7] == 'C');
    assert(buffer[8] == 'C');
    assert(buffer[9] == 'C');

    // Test case 5: Clearing a buffer with size larger than buffer length
    memset(buffer, 'D', 10);
    ft_bzero(buffer, 15);
    for (int i = 0; i < 10; i++)
        assert(buffer[i] == 0);
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
