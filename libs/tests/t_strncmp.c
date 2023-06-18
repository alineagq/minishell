/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_strncmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 16:07:56 by fsuomins          #+#    #+#             */
/*   Updated: 2023/06/18 16:09:13 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../includes/minunit.h"
#include <string.h>
#include "../libft.h"

// Test if ft_strncmp returns 0 when comparing two equal strings
MU_TEST(test_strncmp_equal_strings)
{
    const char *s1 = "Hello";
    const char *s2 = "Hello";
    int result = ft_strncmp(s1, s2, 5);
    mu_assert(result == 0, "Failed to return 0 for equal strings");
}

// Test if ft_strncmp returns a negative value when the first string is less than the second string
MU_TEST(test_strncmp_less_than)
{
    const char *s1 = "Apple";
    const char *s2 = "Banana";
    int result = ft_strncmp(s1, s2, 5);
    mu_assert(result < 0, "Failed to return a negative value for s1 < s2");
}

// Test if ft_strncmp returns a positive value when the first string is greater than the second string
MU_TEST(test_strncmp_greater_than)
{
    const char *s1 = "Banana";
    const char *s2 = "Apple";
    int result = ft_strncmp(s1, s2, 5);
    mu_assert(result > 0, "Failed to return a positive value for s1 > s2");
}

MU_TEST_SUITE(test_strncmp_suite)
{
    MU_RUN_TEST(test_strncmp_equal_strings);
    MU_RUN_TEST(test_strncmp_less_than);
    MU_RUN_TEST(test_strncmp_greater_than);
}

int main(void)
{
    MU_RUN_SUITE(test_strncmp_suite);
    MU_REPORT();
    return MU_EXIT_CODE;
}
