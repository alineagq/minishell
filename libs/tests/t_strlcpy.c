/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_strlcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 10:06:26 by fsuomins          #+#    #+#             */
/*   Updated: 2023/06/12 15:17:33 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../includes/minunit.h"
#include <string.h>
#include "../libft.h"

MU_TEST(test_ft_strlcpy_case1)
{
    char dst[10];
    const char *src = "Hello";
    size_t maxlen = 10;
    size_t result = ft_strlcpy(dst, src, maxlen);
    mu_assert(strcmp(dst, "Hello") == 0, "Failed to copy source string to destination");
    mu_assert(result == 5, "Incorrect return value");
}

MU_TEST(test_ft_strlcpy_case2)
{
    char dst[10];
    const char *src = "World";
    size_t maxlen = sizeof(dst);
    size_t result = ft_strlcpy(dst, src, maxlen);
    mu_assert(strcmp(dst, "World") == 0, "Failed to copy entire source string to destination");
    mu_assert(result == 5, "Incorrect return value");
}

MU_TEST(test_ft_strlcpy_case3)
{
    char dst[10];
    const char *src = "OpenAI";
    size_t maxlen = sizeof(dst);
    size_t result = ft_strlcpy(dst, src, maxlen);
    mu_assert(strncmp(dst, src, maxlen) == 0, "Failed to copy subset of source string to destination");
    mu_assert(result == strlen(src), "Incorrect return value");
}

MU_TEST(test_ft_strlcpy_case4)
{
    char dst[10];
    const char *src = "GPT-3.5";
    size_t maxlen = 0;
    size_t result = ft_strlcpy(dst, src, maxlen);
    mu_assert(dst[0] == '\0', "Failed to handle maxlen = 0");
    mu_assert(result == 7, "Incorrect return value");
}

MU_TEST_SUITE(test_suite)
{
    MU_RUN_TEST(test_ft_strlcpy_case1);
    MU_RUN_TEST(test_ft_strlcpy_case2);
    MU_RUN_TEST(test_ft_strlcpy_case3);
    MU_RUN_TEST(test_ft_strlcpy_case4);
}

int main(void)
{
    MU_RUN_SUITE(test_suite);
    MU_REPORT();
    return MU_EXIT_CODE;
}
