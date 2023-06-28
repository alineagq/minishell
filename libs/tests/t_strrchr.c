/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_strrchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 14:24:18 by fsuomins          #+#    #+#             */
/*   Updated: 2023/06/18 15:34:15 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "../includes/minunit.h"
#include "../libft.h"

MU_TEST(test_strrch_returns_correct_pointer)
{
    const char str[] = "Hello, world!";
    const char target = 'o';
    const char *result = ft_strrchr(str, target);
    const char *expected = "orld!";

    mu_assert_string_eq(result, expected);
}

// Test if ft_strrchr returns NULL when the character is not found in the string
MU_TEST(test_strrch_returns_null_when_character_not_found)
{
    const char str[] = "Hello, world!";
    const char target = 'z';
    const char *result = ft_strrchr(str, target);
    mu_assert(result == NULL, "Failed to return NULL when 'z' is not found");
}

// Test if ft_strrchr correctly handles an empty string
MU_TEST(test_strrch_handles_empty_string)
{
    const char str[] = "";
    const char target = 'a';
    const char *result = ft_strrchr(str, target);
    mu_assert(result == NULL, "Failed to handle empty string correctly");
}

MU_TEST_SUITE(test_strrch_suite)
{
    MU_RUN_TEST(test_strrch_returns_correct_pointer);
    MU_RUN_TEST(test_strrch_returns_null_when_character_not_found);
    MU_RUN_TEST(test_strrch_handles_empty_string);
}

int main(void)
{
    MU_RUN_SUITE(test_strrch_suite);
    MU_REPORT();
    return MU_EXIT_CODE;
}
