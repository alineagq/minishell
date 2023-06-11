/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_memcpy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 19:14:43 by fsuomins          #+#    #+#             */
/*   Updated: 2023/06/10 21:10:14 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minunit.h"
#include "../libft.h"
#include <stdio.h>
#include <string.h>

MU_TEST(test_memcpy_same_dest_and_src)
{
    char src[] = "Hello, World!";
    char dest[] = "1234567890";
    size_t len = strlen(src) + 1;

    char *result = ft_memcpy(dest, src, len);

    mu_assert(result == dest, "Fail on same dest and src");
    mu_assert(strcmp(dest, "Hello, World!") == 0, "Fail on same dest and src");
}

MU_TEST(test_memcpy_different_dest_and_src)
{
    char src[] = "Hello, World!";
    char dest[20];
    size_t len = strlen(src) + 1;

    char *result = ft_memcpy(dest, src, len);

    mu_assert(result == dest, "Fail on different dest and src");
    mu_assert(strcmp(dest, "Hello, World!") == 0, "Fail on different dest and src");
}

MU_TEST(test_memcpy_overlapping_regions)
{
    char src[] = "Hello, World!";
    char dest[] = "1234567890";
    size_t len = strlen(src) + 1;

    char *result = ft_memcpy(dest + 5, src, len);

    mu_assert(result == dest + 5, "Fail on overlapping regions");
    mu_assert(strcmp(dest, "12345Hello, World!") == 0, "Fail on overlapping regions");
}

MU_TEST(test_memcpy_return_value)
{
    char src[] = "Hello, World!";
    char dest[20];
    size_t len = strlen(src) + 1;

    char *result = ft_memcpy(dest, src, len);

    mu_assert(result == dest, "Fail on return value");
}

MU_TEST(test_memcpy_null_pointer)
{
    char src[] = "Hello, World!";
    char *dest = NULL;
    size_t len = strlen(src) + 1;

    char *result = ft_memcpy(dest, src, len);

    mu_assert(result == dest, "Fail on null pointer");
    mu_assert(dest == NULL, "Fail on null pointer");
}

MU_TEST_SUITE(test_suite)
{
    MU_RUN_TEST(test_memcpy_same_dest_and_src);
	MU_RUN_TEST(test_memcpy_different_dest_and_src);
    MU_RUN_TEST(test_memcpy_overlapping_regions);
    MU_RUN_TEST(test_memcpy_return_value);
    MU_RUN_TEST(test_memcpy_null_pointer);
}

int main(void)
{
    MU_RUN_SUITE(test_suite);
    MU_REPORT();
    return MU_EXIT_CODE;
}
