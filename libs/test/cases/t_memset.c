/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_memset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqueiroz <aqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 17:41:48 by fsuomins          #+#    #+#             */
/*   Updated: 2023/07/21 23:20:02 by aqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../files/test.h"

void t_memset(void)
{
	printf("Testing: %s\n", strrchr(__FILE__, '/') + 1);
    init_report();

    // Teste 1: Preenchendo uma área de memória com um valor específico
    char str1[10] = "Hello";
    ft_memset(str1, 'A', 5);
    assert(memcmp(str1, "AAAAA", 5) == 0);

    // Teste 2: Preenchendo uma área de memória com zero
    int arr2[5] = {1, 2, 3, 4, 5};
    ft_memset(arr2, 0, sizeof(int) * 5);
    for (int i = 0; i < 5; i++) {
        assert(arr2[i] == 0);
    }

    int arr4[5] = {1, 2, 3, 4, 5};
    int *result4 = ft_memset(arr4, 0, sizeof(int) * 5);
    assert(result4 == arr4);


    report();
}
