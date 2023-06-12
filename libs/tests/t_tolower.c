/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_tolower.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 15:43:53 by fsuomins          #+#    #+#             */
/*   Updated: 2023/06/12 15:48:30 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../includes/minunit.h"
#include "../libft.h"

MU_TEST(test_ft_tolower_case1)
{
    int c = 'A';
    int result = ft_tolower(c);
    mu_assert(result == 'a', "Incorrect conversion");
}

MU_TEST(test_ft_tolower_case2)
{
    int c = 'z';
    int result = ft_tolower(c);
    mu_assert(result == 'z', "Incorrect conversion");
}

MU_TEST(test_ft_tolower_case3)
{
    int c = '7';
    int result = ft_tolower(c);
    mu_assert(result == '7', "Incorrect conversion");
}

MU_TEST(test_ft_tolower_case4)
{
    int c = ' ';
    int result = ft_tolower(c);
    mu_assert(result == ' ', "Incorrect conversion");
}

MU_TEST_SUITE(test_suite)
{
    MU_RUN_TEST(test_ft_tolower_case1);
    MU_RUN_TEST(test_ft_tolower_case2);
    MU_RUN_TEST(test_ft_tolower_case3);
    MU_RUN_TEST(test_ft_tolower_case4);
}

int main(void)
{
    MU_RUN_SUITE(test_suite);
    MU_REPORT();
    return MU_EXIT_CODE;
}
