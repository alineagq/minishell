/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 01:50:00 by aqueiroz          #+#    #+#             */
/*   Updated: 2023/07/23 10:05:43 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void	push_str(char ***array, int *size, const char *string)
{
	(*size)++;
	*array = realloc(*array, sizeof(char *) * (*size));
	(*array)[*size - 1] = malloc(strlen(string) + 1);
	strcpy((*array)[*size - 1], string);
}

int	main(void)
{
	t_islower();
	t_isupper();
	t_isalpha();
	t_isdigit();
	t_isalnum();
	t_isascii();
	t_isprint();
	t_strlen();
	t_memset();
	t_bzero();
	t_calloc();
	t_memchr();
	t_memcpy();
	t_memmove();
	t_strlcpy();
	t_tolower();
	t_toupper();
	t_strchr();
	t_strlcat();
	t_strncmp();
	t_strrchr();
	t_memcmp();
	t_strnstr();
	t_atoi();
	t_strdup();
	t_substr();
	t_strjoin();
	t_strtrim();
	t_split();
	t_itoa();
	t_strmapi();
	t_striteri();
	t_putchar_fd();
}
