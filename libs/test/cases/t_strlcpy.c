/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_strlcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqueiroz <aqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 10:06:26 by fsuomins          #+#    #+#             */
/*   Updated: 2023/07/21 23:20:02 by aqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../files/test.h"

void	t_strlcpy(void)
{
	printf("Testing: %s\n", strrchr(__FILE__, '/') + 1);
    init_report();

	char dest1[10];
	char dest2[10];
	char dest3[10];
	char dest4[10];
	char dest5[10];

	// Test case 1: Source string fits entirely within destination buffer
	assert(ft_strlcpy(dest1, "Hello", sizeof(dest1)) == 5);
	assert(strcmp(dest1, "Hello") == 0);

	// Test case 2: Source string larger than destination buffer
	assert(ft_strlcpy(dest2, "Hello, World!", sizeof(dest2)) == 13);
	assert(strcmp(dest2, "Hello, Wo") == 0);

	// Test case 3: Empty source string
	assert(ft_strlcpy(dest3, "", sizeof(dest3)) == 0);
	assert(strcmp(dest3, "") == 0);

	// Test case 4: Destination buffer size is 0
	assert(ft_strlcpy(dest4, "Hello", 0) == 5);

	// Test case 5: Source string fits entirely within destination buffer,
	// but destination buffer is smaller than the source string
	assert(ft_strlcpy(dest5, "Hello, World!", 5) == 13);
	assert(strcmp(dest5, "Hell\0") == 0);

	report();
}
