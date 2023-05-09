/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 17:42:50 by fsuomins          #+#    #+#             */
/*   Updated: 2023/05/09 20:45:44 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*Description

The C library function void *memset(void *str, int c, size_t n) copies the 
character c (an unsigned char) to the first n characters of the string
pointed to, by the argument str.
 
Declaration

Following is the declaration for memset() function.

void *memset(void *str, int c, size_t n)

Parameters

    str − This is a pointer to the block of memory to fill.

    c − This is the value to be set. The value is passed as an int,
    but the function fills the block of memory using the unsigned char
    conversion of this value.

    n − This is the number of bytes to be set to the value.

Return Value

This function returns a pointer to the memory area str.*/

void *ft_memset(void *ptr, int value, size_t num)
{
    unsigned char *p = ptr;
    unsigned char val = (unsigned char)value;

    for (size_t i = 0; i < num; i++) {
        p[i] = val;
    }

    return ptr;
}
