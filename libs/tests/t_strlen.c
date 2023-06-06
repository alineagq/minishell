/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_strlen.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 20:30:51 by fsuomins          #+#    #+#             */
/*   Updated: 2023/05/09 20:10:56 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "minunit.h"
#include "../libft.h"

MU_TEST(test_ft_strlen)
{
    const char *str1 = "hello world";
    mu_assert_int_eq(strlen(str1), ft_strlen(str1));
    
    const char *str2 = "This is a longer string";
    mu_assert_int_eq(strlen(str2), ft_strlen(str2));
    
    const char *str3 = "12345";
    mu_assert_int_eq(strlen(str3), ft_strlen(str3));
}

MU_TEST_SUITE(test_suite)
{
    MU_RUN_TEST(test_ft_strlen);
}

int main(int argc, char *argv[])
{
    MU_RUN_SUITE(test_suite);
    MU_REPORT();
    return MU_EXIT_CODE;
}

//this test was created using help chatgpt;
