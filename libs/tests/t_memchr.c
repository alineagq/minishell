/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_memchr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 16:48:24 by fsuomins          #+#    #+#             */
/*   Updated: 2023/06/18 16:50:13 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "../includes/minunit.h"
#include "../libft.h"

// Test if ft_memchr returns the correct pointer to the first occurrence of a byte in a memory block
MU_TEST(test_memchr_returns_correct_pointer)
{
    unsigned char bytes[] = {0x12, 0x34, 0x56, 0x78, 0x9A};
    unsigned char target = 0x56;
    size_t size = sizeof(bytes);
    void *result = ft_memchr(bytes, target, size);
    mu_assert(result == &bytes[2], "Failed to return the correct pointer to the first occurrence of the byte");
}

// Test if ft_memchr returns NULL when the byte is not found in the memory block
MU_TEST(test_memchr_returns_null_when_byte_not_found)
{
    unsigned char bytes[] = {0x12, 0x34, 0x56, 0x78, 0x9A};
    unsigned char target = 0xAB;
    size_t size = sizeof(bytes);
    void *result = ft_memchr(bytes, target, size);
    mu_assert(result == NULL, "Failed to return NULL when the byte is not found");
}

// Test if ft_memchr works correctly with a size of 0
MU_TEST(test_memchr_works_with_size_0)
{
    unsigned char bytes[] = {0x12, 0x34, 0x56, 0x78, 0x9A};
    unsigned char target = 0x12;
    size_t size = 0;
    void *result = ft_memchr(bytes, target, size);
    mu_assert(result == NULL, "Failed to work correctly with size 0");
}

MU_TEST_SUITE(test_memchr_suite)
{
    MU_RUN_TEST(test_memchr_returns_correct_pointer);
    MU_RUN_TEST(test_memchr_returns_null_when_byte_not_found);
    MU_RUN_TEST(test_memchr_works_with_size_0);
}

int main(void)
{
    MU_RUN_SUITE(test_memchr_suite);
    MU_REPORT();
    return MU_EXIT_CODE;
}
