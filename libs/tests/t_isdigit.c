/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_isdigit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by                   #+#    #+#             */
/*   Updated: 2023/06/10 15:35:55 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h>
#include "../includes/minunit.h"
#include "../libft.h"
#include <stdio.h>
#include <ctype.h>


int is_symbol(int character)
{
    if ((character >= 33 && character <= 47) || (character >= 58 && character <= 64) ||
        (character >= 91 && character <= 96) || (character >= 123 && character <= 126))
        return 1;
    return 0;
}

int iscommands(int c)
{
    int result = 0;
    if (c >= 0 && c <= 32)
    {
        result = 1; // c is within ASCII range 0 to 32
    }
    return result;
}

MU_TEST(test_if_symbols_is_alpha)
{
    int i;
    for (i = 0; i < 127; i++)
    {
        if (is_symbol(i))
            mu_assert(ft_isdigit(i) == isdigit(i), "Fail on symbols values");
    }
}

MU_TEST(test_if_spaces_is_alpha)
{
    int i;
    for (i = 0; i < 127; i++)
    {
        if (isspace(i))
            mu_assert(ft_isdigit(i) == isdigit(i), "Fail on spaces values");
    }
}

MU_TEST(test_if_lower_is_alpha)
{
    int i;
    for (i = 0; i < 127; i++)
    {
        if (islower(i))
            mu_assert(ft_isdigit(i) == isdigit(i), "Fail on lower values");
    }
}

MU_TEST(test_if_upper_is_alpha)
{
    int i;
    for (i = 0; i < 127; i++)
    {
        if (isupper(i))
            mu_assert(ft_isdigit(i) == isdigit(i), "Fail on upper values");
    }
}

MU_TEST(test_if_not_ascii_is_alpha)
{
    int i;
    for (i = 0; i < 127; i++)
    {
        if (!isascii(i))
            mu_assert(ft_isdigit(i) == isdigit(i), "Fail on not ASCII values");
    }
}
MU_TEST(test_if_number_is_alpha)
{
    int i;
    for (i = 0; i < 127; i++)
    {
        if (isdigit(i))
            mu_assert(ft_isdigit(i), "Fail on number values");
        else
            mu_assert(!ft_isdigit(i), "Fail on non-number values");
    }
}

MU_TEST(test_if_commands_is_alpha)
{
    int i;
    for (i = 0; i < 127; i++)
    {
        if (iscommands(i))
            mu_assert(ft_isdigit(i) == isdigit(i), "Fail on commands ascii values");
    }
}

MU_TEST_SUITE(test_suite)
{
    MU_RUN_TEST(test_if_symbols_is_alpha);
    MU_RUN_TEST(test_if_spaces_is_alpha);
    MU_RUN_TEST(test_if_lower_is_alpha);
    MU_RUN_TEST(test_if_upper_is_alpha);
    MU_RUN_TEST(test_if_not_ascii_is_alpha);
    MU_RUN_TEST(test_if_number_is_alpha);
    MU_RUN_TEST(test_if_commands_is_alpha);
}

int main()
{
    MU_RUN_SUITE(test_suite);
    MU_REPORT();
    return 0;
}
