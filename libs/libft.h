/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 23:19:53 by fsuomins          #+#    #+#             */
/*   Updated: 2023/05/09 20:45:32 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
#include <string.h>

int     ft_isalpha(int c_is_a_alpha);
int		ft_isdigit(int c_is_a_digit);
int		ft_isascii(int c_is_a_ascii);
int     ft_isalnum(int c_is_a_alnum);
int     ft_isprint(int c_is_printable);
size_t  ft_strlen(const char *str);
void *ft_memset(void *ptr, int value, size_t num);

#endif
