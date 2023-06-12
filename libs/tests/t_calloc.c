/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_calloc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 15:30:23 by fsuomins          #+#    #+#             */
/*   Updated: 2023/06/12 15:38:26 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../includes/minunit.h"
#include <string.h>
#include "../libft.h"

MU_TEST(test_ft_calloc_case1)
{
    size_t count = 5;
	size_t size = 10;
	void *result = ft_calloc(count, size);
    mu_assert(result != NULL, "Failed to allocate memory");

    // Verificar se a memória alocada foi limpa com zeros
    unsigned char *ptr = (unsigned char *)result;
    for (size_t i = 0; i < count * size; i++) {
        mu_assert(ptr[i] == 0, "Memory is not zero-initialized");
    }

    free(result);
}

MU_TEST(test_ft_calloc_case2)
{
    size_t count = 0;
	size_t size = 10;
	void *result = ft_calloc(count, size);
    mu_assert(result == NULL, "Failed to allocate memory");

// Não há necessidade de verificar a inicialização, pois não há memória alocada

    free(result);
}

MU_TEST(test_ft_calloc_case3)
{
    size_t count = 5;
    size_t size = 0;
    void *result = ft_calloc(count, size);
    mu_assert(result == NULL, "Failed to allocate memory");
    
    // Não há necessidade de verificar a inicialização, pois não há memória alocada
    
    free(result);
}

MU_TEST_SUITE(test_suite)
{
    MU_RUN_TEST(test_ft_calloc_case1);
    MU_RUN_TEST(test_ft_calloc_case2);
    MU_RUN_TEST(test_ft_calloc_case3);
}

int main(void)
{
    MU_RUN_SUITE(test_suite);
    MU_REPORT();
    return MU_EXIT_CODE;
}
