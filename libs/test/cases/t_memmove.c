/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_memmove.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqueiroz <aqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 15:59:50 by fsuomins          #+#    #+#             */
/*   Updated: 2023/07/21 23:27:54 by aqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../files/test.h"

void t_memmove(void)
{
    printf("Testing: %s\n", strrchr(__FILE__, '/') + 1);
    init_report();

    // Test case 1: Moving a string to a destination buffer
    char src1[] = "Hello, World!";
    char dest1[20];
    ft_memmove(dest1, src1, strlen(src1) + 1);
    assert(strcmp(dest1, src1) == 0);

    // Test case 2: Moving an empty string to a destination buffer
    char src2[] = "";
    char dest2[10];
    ft_memmove(dest2, src2, strlen(src2) + 1);
    assert(strcmp(dest2, src2) == 0);

    // Test case 3: Moving a portion of a string to a destination buffer
    char src3[] = "Hello, World!";
    char dest3[10];
    ft_memmove(dest3, src3 + 7, strlen(src3) - 6);
    assert(strcmp(dest3, "World!") == 0);


    // Test case 4: Copying to overlapping memory regions
  
	char src4[] = "Hello, World!";
    char dest4[20];
    ft_memmove(dest4, src4, strlen("Hello, World!") + 1);

    int bytes = strlen(dest4) - 6;
    ft_memmove(dest4 + 7, dest4, bytes);

    char *expected = "Hello, Hello, ";
    for (int i = 0; i < bytes - 1; i++)
    {
        assert(dest4[i] == expected[i]);
    }
    
    report();
}