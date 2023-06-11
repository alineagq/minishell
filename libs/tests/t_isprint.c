/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_isprint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 09:36:19 by aqueiroz          #+#    #+#             */
/*   Updated: 2023/06/10 15:52:22 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minunit.h"
#include "../libft.h"
#include <stdio.h>
#include <ctype.h>

MU_TEST(test_if_commands_is_print)
{
    for (int i = 0; i < 128; i++)
    {
        if (i >= 0 && i <= 31)
            mu_assert(ft_isprint(i) == 0, "Fail on commands ascii values");
    }
}

MU_TEST(test_if_number_is_print)
{
    for (int i = 0; i < 128; i++)
    {
        if (i >= 48 && i <= 57)
            mu_assert(ft_isprint(i) == 1, "Fail on number values");
    }
}

MU_TEST(test_if_symbols_is_print)
{
    for (int i = 0; i < 128; i++)
    {
        if ((i >= 33 && i <= 47) || (i >= 58 && i <= 64) || (i >= 91 && i <= 96) || (i >= 123 && i <= 126))
            mu_assert(ft_isprint(i) == 1, "Fail on symbols values");
        
    }
}

MU_TEST(test_if_lower_is_print)
{
    for (int i = 0; i < 128; i++)
    {
        if (i >= 97 && i <= 122)
            mu_assert(ft_isprint(i) == 1, "Fail on lower values");
    
    }
}

MU_TEST(test_if_upper_is_print)
{
    for (int i = 0; i < 128; i++)
    {
        if (i >= 65 && i <= 90)
            mu_assert(ft_isprint(i) == 1, "Fail on upper values");
    }
}

MU_TEST(test_if_spaces_is_print)
{
    for (int i = 0; i < 128; i++)
    {
        if (i == 32)
            mu_assert(ft_isprint(i) == 1, "Fail on spaces values");
       
    }
}

MU_TEST_SUITE(test_suite)
{
    MU_RUN_TEST(test_if_symbols_is_print);
    MU_RUN_TEST(test_if_spaces_is_print);
    MU_RUN_TEST(test_if_lower_is_print);
    MU_RUN_TEST(test_if_upper_is_print);
    MU_RUN_TEST(test_if_number_is_print);
    MU_RUN_TEST(test_if_commands_is_print);
}

int main(void)
{
    MU_RUN_SUITE(test_suite);
    MU_REPORT();
    return MU_EXIT_CODE;
}

