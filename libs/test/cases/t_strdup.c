/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_strdup.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqueiroz <aqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 22:05:21 by fsuomins          #+#    #+#             */
/*   Updated: 2023/07/21 23:20:02 by aqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../files/test.h"

void    t_strdup(void)
{
    printf("Testing: %s\n", strrchr(__FILE__, '/') + 1);
    init_report();

    // Test case 1: Non-empty string
    const char *str1 = "Hello, World!";
    char *result1 = ft_strdup(str1);
    assert(strcmp(result1, str1) == 0);
    free(result1);

    // Test case 2: Empty string
    const char *str2 = "";
    char *result2 = ft_strdup(str2);
    assert(strcmp(result2, str2) == 0);
    free(result2);

    // Test case 3: String with special characters
    const char *str3 = "Testing special characters: !@#$%^&*()";
    char *result3 = ft_strdup(str3);
    assert(strcmp(result3, str3) == 0);
    free(result3);

    report();

}