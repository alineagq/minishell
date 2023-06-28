/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_bzero.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 20:11:13 by fsuomins          #+#    #+#             */
/*   Updated: 2023/06/10 15:36:20 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minunit.h"
#include "../libft.h"
#include <string.h>


int is_symbol(int character) 
{
  //  int character = 65;
    if ((character >= 33 && character <= 47) || (character >= 58 && character <= 64) ||
        (character >= 91 && character <= 96) || (character >= 123 && character <= 126))
		return (1);
	return (0);
}

int iscommands(int c) {
    int result = 0;
    if (c >= 0 && c <= 32) {
        result = 1; // c is within ASCII range 0 to 32
    }
    return result;
}

MU_TEST(test_ft_bzero)
{
    char str1[10] = "Hello";
    char zeros[10] = {0};

    ft_bzero(str1, 5);
    mu_assert(memcmp(str1, zeros, 5) == 0, "Fail to zero out memory");

    // Additional test case
    char str3[10] = "Testing";

    ft_bzero(str3, 7);
    mu_assert(memcmp(str3, zeros, 7) == 0, "Fail to zero out memory");
}

MU_TEST_SUITE(test_suite)
{
    MU_RUN_TEST(test_ft_bzero);
}

int main(void)
{
    MU_RUN_SUITE(test_suite);
    MU_REPORT();
    return MU_EXIT_CODE;
}
