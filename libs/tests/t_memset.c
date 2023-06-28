/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_memset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 17:41:48 by fsuomins          #+#    #+#             */
/*   Updated: 2023/06/11 10:16:40 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../includes/minunit.h"
#include <ctype.h>
#include "../libft.h"

// Test if ft_memset sets all bytes to the given value
MU_TEST(test_memset_sets_all_bytes)
{
    char str[] = "Hello, world!";
    ft_memset(str, '*', sizeof(str));
    for (int i = 0; i < sizeof(str); i++) {
        mu_assert(str[i] == '*', "Failed to set all bytes to '*'");
    }
}

// Test if ft_memset correctly sets a subset of bytes to the given value
MU_TEST(test_memset_sets_subset_of_bytes)
{
    char str[] = "Hello, world!";
    ft_memset(str + 7, '-', 5);
    mu_assert(strcmp(str, "Hello, -----!") == 0, "Failed to set subset of bytes to '-'");
}

// Test if ft_memset works correctly with a size of 0
MU_TEST(test_memset_does_nothing_with_size_0)
{
    char str[] = "Hello, world!";
    ft_memset(str, '*', 0);
    mu_assert(strcmp(str, "Hello, world!") == 0, "Failed to do nothing with size 0");
}

MU_TEST_SUITE(test_memset_suite)
{
	MU_RUN_TEST(test_memset_sets_all_bytes);
	MU_RUN_TEST(test_memset_sets_subset_of_bytes);
	MU_RUN_TEST(test_memset_does_nothing_with_size_0);
}

int main(void)
{
    MU_RUN_SUITE(test_memset_suite);
    MU_REPORT();
    return MU_EXIT_CODE;
}

/*
#include <stdio.h>
#include <string.h>
#include "minunit.h"

#define BUFFER_SIZE 10

MU_TEST(test_memset_edge_case)
{
    char buffer[BUFFER_SIZE];

    // Test setting the buffer to all 0xFF bytes using ft_memset
    ft_memset(buffer, 0xFF, BUFFER_SIZE);
    mu_assert(memcmp(buffer, "\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF", BUFFER_SIZE) == 0, "ft_memset failed to set buffer to 0xFF");

    // Test setting the buffer to all 0x00 bytes using ft_memset
    ft_memset(buffer, 0x00, BUFFER_SIZE);
    mu_assert(memcmp(buffer, "\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00", BUFFER_SIZE) == 0, "ft_memset failed to set buffer to 0x00");
}

MU_TEST_SUITE(test_suite)
{
    MU_RUN_TEST(test_memset_edge_case);
}

int main()
{
    MU_RUN_SUITE(test_suite);
    MU_REPORT();
    return 0;
}
*/
