/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqueiroz <aqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 23:19:53 by fsuomins          #+#    #+#             */
/*   Updated: 2023/06/10 19:25:14 by aqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# define BUFFER_SIZE 1

int		ft_isalpha(int c_is_a_alpha);
int		ft_isdigit(int c_is_a_digit);
int		ft_isascii(int c_is_a_ascii);
int		ft_isalnum(int c_is_a_alnum);
int		ft_isprint(int c_is_printable);
size_t	ft_strlen(const char *str);
void	*ft_memset(void *ptr, int value, size_t num);
void	ft_bzero(void *s, size_t n);
char	*get_next_line(int fd);

#endif
