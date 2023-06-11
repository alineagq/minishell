/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_isalpha.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqueiroz <aqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by                   #+#    #+#             */
/*   Updated: 2023/06/10 15:36:28 by aqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../minunit.h"
#include "../libft.h"
#include <ctype.h>

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

MU_TEST(test_if_commands_is_alpha)
{
	int	i;

	i = 0;
	while (i < 127)
	{
		if (iscommands(i))
			mu_assert(ft_isalpha(i) == isalpha(i), "Fail on commands ascii values");
		i++;
	}
}

MU_TEST(test_if_number_is_alpha)
{
	int	i;

	i = 0;
	while (i < 127)
	{
		if (isdigit(i))
			mu_assert(ft_isalpha(i) == isalpha(i), "Fail on number values");
		i++;
	}
}

MU_TEST(test_if_symbols_is_alpha)
{
	int	i;

	i = 0;
	while (i < 127)
	{
		if (is_symbol(i))
			mu_assert(ft_isalpha(i) == isalpha(i), "Fail on symbols values");
		i++;
	}
}

MU_TEST(test_if_not_ascii_is_alpha)
{
	int	i;

	i = 0;
	while (i < 127)
	{
		if (!isascii(i))
		{
			printf("%d", i);
			mu_assert(ft_isalpha(i) == isalpha(i), "Fail on not ASCII values");
		}
		i++;
	}
}

MU_TEST(test_if_lower_is_alpha)
{
    int i = 'a';
    while (i <= 'z')
    {
        mu_assert(ft_isalpha(i) == 1, "Fail on lower values");
        i++;
    }
}

MU_TEST(test_if_upper_is_alpha)
{
    int i = 'A';
    while (i <= 'Z')
    {
        mu_assert(ft_isalpha(i) == 1, "Fail on upper values");
        i++;
    }
}


MU_TEST(test_if_spaces_is_alpha)
{
	int	i;

	i = 0;
	while (i < 127)
	{
		if (isspace(i))
			mu_assert(ft_isalpha(i) == isalpha(i), "Fail on spaces values");
		i++;
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
    return (0);
}
