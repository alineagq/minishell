/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_strjoin.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqueiroz <aqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 14:38:51 by fsuomins          #+#    #+#             */
/*   Updated: 2023/07/21 23:20:02 by aqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../files/test.h"

void t_strjoin(void)
{
    printf("Testing: %s\n", strrchr(__FILE__, '/') + 1);
    init_report();
    
    // Test case 1: Concatenate two non-empty strings
    const char *s1 = "Hello, ";
    const char *s2 = "World!";
    char *result1 = ft_strjoin(s1, s2);
    assert(strcmp(result1, "Hello, World!") == 0);
    free(result1);

    // Test case 2: Concatenate an empty string with a non-empty string
    const char *s3 = "";
    const char *s4 = "Testing";
    char *result2 = ft_strjoin(s3, s4);
    assert(strcmp(result2, "Testing") == 0);
    free(result2);

    // Test case 3: Concatenate two empty strings
    const char *s5 = "";
    const char *s6 = "";
    char *result3 = ft_strjoin(s5, s6);
    assert(strcmp(result3, "") == 0);
    free(result3);

    // Test case 4: Concatenate NULL strings
    const char *s7 = NULL;
    const char *s8 = "Test";
    char *result4 = ft_strjoin(s7, s8);
    assert(result4 == NULL);

    const char *s9 = "Test";
    const char *s10 = NULL;
    char *result5 = ft_strjoin(s9, s10);
    assert(result5 == NULL);

    const char *s11 = NULL;
    const char *s12 = NULL;
    char *result6 = ft_strjoin(s11, s12);
    assert(result6 == NULL);

    report();
}
