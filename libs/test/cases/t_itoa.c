/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_itoa.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqueiroz <aqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 22:19:25 by fsuomins          #+#    #+#             */
/*   Updated: 2023/07/21 23:36:39 by aqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../files/test.h"

void t_itoa(void)
{
    printf("Testing: %s\n", strrchr(__FILE__, '/') + 1);
    init_report();

    // Test case 1: Positive number
    int n1 = 12345;
    char* result1 = ft_itoa(n1);
    assert(strcmp(result1, "12345") == 0);
    free(result1);

    // Test case 2: Negative number
    int n2 = -98765;
    char* result2 = ft_itoa(n2);
    assert(strcmp(result2, "-98765") == 0);
    free(result2);

    // Test case 3: Zero
    int n3 = 0;
    char* result3 = ft_itoa(n3);
    assert(strcmp(result3, "0") == 0);
    free(result3);

    report();
}
