/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_strlcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 16:03:43 by fsuomins          #+#    #+#             */
/*   Updated: 2023/06/12 16:17:45 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../includes/minunit.h"
#include <string.h>
#include "../libft.h"

MU_TEST(test_ft_strlcat_case1)
{
    char dst[15] = "Hello";
    const char *src = " World";
    size_t dstsize = sizeof(dst);
    size_t result = ft_strlcat(dst, src, dstsize);
    mu_assert(strcmp(dst, "Hello World") == 0, "Failed to concatenate strings");
    mu_assert(result == 11, "Incorrect return value");
}

MU_TEST(test_ft_strlcat_case2)
{
    char dst[10] = "Open";
    const char *src = "AI";
    size_t dstsize = sizeof(dst);
    size_t result = ft_strlcat(dst, src, dstsize);
    mu_assert(strcmp(dst, "OpenAI") == 0, "Failed to concatenate strings");
    mu_assert(result == 6, "Incorrect return value");
}

MU_TEST(test_ft_strlcat_case3)
{
    char dst[8] = "123";
    const char *src = "456";
    size_t dstsize = sizeof(dst);
    size_t result = ft_strlcat(dst, src, dstsize);
    mu_assert(result < dstsize, "Destination buffer should not be truncated");
    mu_assert(strcmp(dst, "123") == 0, "Destination buffer should not be modified");
    mu_assert(result == 6, "Incorrect return value");
}

MU_TEST_SUITE(test_suite)
{
    MU_RUN_TEST(test_ft_strlcat_case1);
    MU_RUN_TEST(test_ft_strlcat_case2);
    MU_RUN_TEST(test_ft_strlcat_case3);
}

int main(void)
{
    MU_RUN_SUITE(test_suite);
    MU_REPORT();
    return MU_EXIT_CODE;
}
