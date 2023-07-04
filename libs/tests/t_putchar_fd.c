/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_putchar_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 22:52:59 by fsuomins          #+#    #+#             */
/*   Updated: 2023/07/03 22:57:28 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void t_putchar_fd(void)
{
	char** stringArray = NULL;
    int arraySize = 0;
    // int counter = 1;

    printf("> Testing: %s\n", __FILE__);

    // Test case 1: Write a single character to file descriptor 1 (stdout)
    char ch1 = 'A';
    int fd1 = 1; // stdout
    ft_putchar_fd(ch1, fd1); // The character 'A' will be printed to the console

    // Test case 2: Write a single character to file descriptor 2 (stderr)
    char ch2 = 'B';
    int fd2 = 2; // stderr
    ft_putchar_fd(ch2, fd2); // The character 'B' will be printed to the console as an error

    // Additional test cases...
	if (arraySize != 0)
    {
        printf("\n");
        for (int i = 0; i < arraySize; i++)
        {
            printf("\033[0mError %d: %s\n", i + 1, stringArray[i]);
        }
    }

    // Free the memory allocated for the strings
    for (int i = 0; i < arraySize; i++)
    {
        free(stringArray[i]);
    }

    // Free the memory allocated for the array
    free(stringArray);

    printf("\n");

}
