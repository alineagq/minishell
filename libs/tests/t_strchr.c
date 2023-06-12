/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_strchr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 15:06:14 by fsuomins          #+#    #+#             */
/*   Updated: 2023/06/12 15:25:05 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../includes/minunit.h"
#include <string.h>
#include "../libft.h"

MU_TEST(test_ft_strchr_case1)
{
    const char *str = "Hello";
    char c = 'e';
    char *result = ft_strchr(str, c);
    mu_assert(result != NULL, "Failed to find character in string");
    mu_assert(*result == c, "Incorrect character found");
}

MU_TEST(test_ft_strchr_case2)
{
    const char *str = "World";
    char c = 'l';
    char *result = ft_strchr(str, c);
    mu_assert(result != NULL, "Failed to find character in string");
    mu_assert(*result == c, "Incorrect character found");
}

MU_TEST(test_ft_strchr_case3)
{
    const char *str = "OpenAI";
    char c = 'A';
    char *result = ft_strchr(str, c);
    mu_assert(result != NULL, "Failed to find character in string");
    mu_assert(*result == c, "Incorrect character found");
}

MU_TEST(test_ft_strchr_case4)
{
    const char *str = "GPT-3.5";
    char c = '9';
    char *result = ft_strchr(str, c);
    mu_assert(result == NULL, "Character found in string when it shouldn't be");
}

MU_TEST_SUITE(test_suite)
{
    MU_RUN_TEST(test_ft_strchr_case1);
    MU_RUN_TEST(test_ft_strchr_case2);
    MU_RUN_TEST(test_ft_strchr_case3);
    MU_RUN_TEST(test_ft_strchr_case4);
}

int main(void)
{
    MU_RUN_SUITE(test_suite);
    MU_REPORT();
    return MU_EXIT_CODE;
}
