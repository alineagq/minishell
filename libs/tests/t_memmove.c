/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_memmove.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 15:59:50 by fsuomins          #+#    #+#             */
/*   Updated: 2023/06/12 16:02:59 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../includes/minunit.h"
#include <string.h>
#include "../libft.h"

MU_TEST(test_ft_memmove_case1)
{
    char src[10] = "Hello";
    char dest[10] = "";
    size_t n = 5;
    void *result = ft_memmove(dest, src, n);
    mu_assert(result == dest, "Incorrect return value");
    mu_assert(memcmp(dest, src, n) == 0, "Failed to copy memory correctly");
}

MU_TEST(test_ft_memmove_case2)
{
    char src[10] = "World";
    char dest[10] = "";
    size_t n = 3;
    void *result = ft_memmove(dest, src, n);
    mu_assert(result == dest, "Incorrect return value");
    mu_assert(memcmp(dest, src, n) == 0, "Failed to copy memory correctly");
}

MU_TEST(test_ft_memmove_case3)
{
    char src[10] = "OpenAI";
    char dest[10] = "";
    size_t n = sizeof(src);
    void *result = ft_memmove(dest, src, n);
    mu_assert(result == dest, "Incorrect return value");
    mu_assert(memcmp(dest, src, n) == 0, "Failed to copy memory correctly");
}

MU_TEST_SUITE(test_suite)
{
    MU_RUN_TEST(test_ft_memmove_case1);
    MU_RUN_TEST(test_ft_memmove_case2);
    MU_RUN_TEST(test_ft_memmove_case3);
}

int main(void)
{
    MU_RUN_SUITE(test_suite);
    MU_REPORT();
    return MU_EXIT_CODE;
}
