/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_toupper.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 15:54:41 by fsuomins          #+#    #+#             */
/*   Updated: 2023/06/12 15:59:04 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../includes/minunit.h"
#include "../libft.h"

MU_TEST(test_ft_toupper_case1)
{
    int c = 'a';
    int result = ft_toupper(c);
    mu_assert(result == 'A', "Incorrect conversion");
}

MU_TEST(test_ft_toupper_case2)
{
    int c = 'Z';
    int result = ft_toupper(c);
    mu_assert(result == 'Z', "Incorrect conversion");
}

MU_TEST(test_ft_toupper_case3)
{
    int c = '7';
    int result = ft_toupper(c);
    mu_assert(result == '7', "Incorrect conversion");
}

MU_TEST(test_ft_toupper_case4)
{
    int c = ' ';
    int result = ft_toupper(c);
    mu_assert(result == ' ', "Incorrect conversion");
}

MU_TEST_SUITE(test_suite)
{
    MU_RUN_TEST(test_ft_toupper_case1);
    MU_RUN_TEST(test_ft_toupper_case2);
    MU_RUN_TEST(test_ft_toupper_case3);
    MU_RUN_TEST(test_ft_toupper_case4);
}

int main(void)
{
    MU_RUN_SUITE(test_suite);
    MU_REPORT();
    return MU_EXIT_CODE;
}
