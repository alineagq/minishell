/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_calloc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 15:30:23 by fsuomins          #+#    #+#             */
/*   Updated: 2023/06/28 17:19:11 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void t_calloc(void)
{
	char** stringArray = NULL;
    int arraySize = 0;
    int counter = 1;
	
    printf("> Testing: %s\n", __FILE__);
    // Test case 1: Allocating and clearing memory for zero elements of size 0
    size_t count1 = 0;
    size_t size1 = 0;
    void* ptr1 = ft_calloc(count1, size1);
    assert(ptr1 == NULL);

    // Test case 2: Allocating and clearing memory for non-zero elements of size 0
    size_t count2 = 5;
    size_t size2 = 0;
    void* ptr2 = ft_calloc(count2, size2);
    assert(ptr2 == NULL);

    // Test case 3: Allocating and clearing memory for non-zero elements of non-zero size
    size_t count3 = 3;
    size_t size3 = 4;
    void* ptr3 = ft_calloc(count3, size3);
    assert(ptr3 != NULL);
    for (size_t i = 0; i < count3 * size3; i++) {
        assert(((char*)ptr3)[i] == 0);
    }
    free(ptr3);

    // Test case 4: Allocating and clearing memory for a large number of elements
    size_t count4 = 10;
    size_t size4 = sizeof(int);
    int* ptr4 = (int*)ft_calloc(count4, size4);
    assert(ptr4 != NULL);
    for (size_t i = 0; i < count4; i++) {
        assert(ptr4[i] == 0);
    }
    free(ptr4);

    // Test case 5: Allocating and clearing memory with size exceeding SIZE_MAX
    size_t count5 = 1;
    size_t size5 = SIZE_MAX;
    void* ptr5 = ft_calloc(count5, size5);
    assert(ptr5 == NULL);
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
