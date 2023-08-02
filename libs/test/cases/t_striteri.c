/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_striteri.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqueiroz <aqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 22:36:18 by fsuomins          #+#    #+#             */
/*   Updated: 2023/07/21 23:38:55 by aqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../files/test.h"

// Helper function to perform an action on each character
static void actionFunction(unsigned int index, char* c)
{
	(void)index; 
    // Example action function: convert lowercase letters to uppercase
    if (*c >= 'a' && *c <= 'z')
        *c = *c - ('a' - 'A');
}

void t_striteri(void)
{
    printf("Testing: %s\n", strrchr(__FILE__, '/') + 1);
    init_report();

    // Test case 1: Convert lowercase to uppercase
    char str1[] = "Hello, World!";
    ft_striteri(str1, actionFunction);
    assert(strcmp(str1, "HELLO, WORLD!") == 0);

    // Test case 2: Empty string
    char str2[] = "";
    ft_striteri(str2, actionFunction);
    assert(strcmp(str2, "") == 0);

    report();
}
