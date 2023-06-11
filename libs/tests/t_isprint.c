/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_isprint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqueiroz <aqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 09:36:19 by aqueiroz          #+#    #+#             */
/*   Updated: 2023/06/10 15:36:39 by aqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../minunit.h"
#include "../libft.h"
#include <ctype.h>

MU_TEST(test_if_commands_is_alpha)
{
    for (int i = 0; i < 128; i++)
    {
        if (i >= 0 && i <= 31)
            mu_assert(ft_isprint(i) == 0, "Fail on commands ascii values");
        else
            mu_assert(ft_isprint(i) == 1, "Fail on non-commands ascii values");
    }
}

MU_TEST(test_if_number_is_alpha)
{
    for (int i = 0; i < 128; i++)
    {
        if (i >= 48 && i <= 57)
            mu_assert(ft_isprint(i) == 1, "Fail on number values");
        else
            mu_assert(ft_isprint(i) == 1, "Fail on non-number values");
    }
}

MU_TEST(test_if_symbols_is_alpha)
{
    for (int i = 0; i < 128; i++)
    {
        if (i >= 33 && i <= 47)
            mu_assert(ft_isprint(i) == 1, "Fail on symbols values");
        else if (i >= 58 && i <= 64)
            mu_assert(ft_isprint(i) == 1, "Fail on symbols values");
        else if (i >= 91 && i <= 96)
            mu_assert(ft_isprint(i) == 1, "Fail on symbols values");
        else if (i >= 123 && i <= 126)
            mu_assert(ft_isprint(i) == 1, "Fail on symbols values");
    }
}

MU_TEST(test_if_lower_is_alpha)
{
    for (int i = 0; i < 128; i++)
    {
        if (i >= 97 && i <= 122)
            mu_assert(ft_isprint(i) == 1, "Fail on lower values");
        else
            mu_assert(ft_isprint(i) == 1, "Fail on non-lower values");
    }
}

MU_TEST(test_if_upper_is_alpha)
{
    for (int i = 0; i < 128; i++)
    {
        if (i >= 65 && i <= 90)
            mu_assert(ft_isprint(i) == 1, "Fail on upper values");
        else
            mu_assert(ft_isprint(i) == 1, "Fail on non-upper values");
    }
}

MU_TEST(test_if_spaces_is_alpha)
{
    for (int i = 0; i < 128; i++)
    {
        if (i == 32)
            mu_assert(ft_isprint(i) == 1, "Fail on spaces values");
        else
            mu_assert(ft_isprint(i) == 1, "Fail on non-spaces values");
    }
}

MU_TEST_SUITE(test_suite)
{
    MU_RUN_TEST(test_if_symbols_is_alpha);
    MU_RUN_TEST(test_if_spaces_is_alpha);
    MU_RUN_TEST(test_if_lower_is_alpha);
    MU_RUN_TEST(test_if_upper_is_alpha);
    MU_RUN_TEST(test_if_number_is_alpha);
    MU_RUN_TEST(test_if_commands_is_alpha);
}

int main(void)
{
    MU_RUN_SUITE(test_suite);
    MU_REPORT();
    return MU_EXIT_CODE;
}
