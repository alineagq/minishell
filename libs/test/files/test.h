/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqueiroz <aqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 03:27:29 by aqueiroz          #+#    #+#             */
/*   Updated: 2023/07/22 01:15:17 by aqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_H
# define TEST_H

// LIBS
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <time.h> 
# include <fcntl.h>
# include "../../libft.h"

// COLORS
# define BLACK "\033[30m"
# define RED "\033[31m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define BLUE "\033[34m"
# define MAGENTA "\033[35m"
# define CYAN "\033[36m"
# define WHITE "\033[37m"
# define RESET "\033[0m"


// ASSERT MACRO
# ifdef NDEBUG
#  define assert(expression) ((void)0)
# else
#  define assert(expression) \
    do { \
        counter++; \
        if (counter > 1) \
            printf(" "); \
        if (expression) { \
            printf("%s%d.OK%s", GREEN, counter, RESET); \
            fflush(stdout); \
		    sucess++; \
        } \
        else { \
            printf("%s%d.Fail%s", RED, counter, RESET); \
            fflush(stdout); \
		    push_str(&stringArray, &arraySize, #expression); \
		    error++; \
        } \
	} while (0)
# endif

// GLOBALS
extern int	counter;
extern int	error;
extern int	sucess;
extern char **stringArray;
extern int  arraySize;

// UTILS
void	push_str(char ***array, int *size, const char *string);
void	clear_report(void);
void	print_report(void);
void	init_report(void);
void	error_log(void);
void	report(void);

// TEST CASES 
void	t_putchar_fd(void);
void	t_striteri(void);
void	t_islower(void);
void	t_isupper(void);
void	t_isalpha(void);
void	t_isdigit(void);
void	t_isalnum(void);
void	t_isascii(void);
void	t_isprint(void);
void	t_strlcpy(void);
void	t_tolower(void);
void	t_toupper(void);
void	t_strlcat(void);
void	t_memmove(void);
void	t_strncmp(void);
void	t_strrchr(void);
void	t_strnstr(void);
void	t_strjoin(void);
void	t_strtrim(void);
void	t_strmapi(void);
void	t_memset(void);
void	t_calloc(void);
void	t_memchr(void);
void	t_memcpy(void);
void	t_strchr(void);
void	t_strlen(void);
void	t_memcmp(void);
void	t_strdup(void);
void	t_substr(void);
void	t_split(void);
void	t_bzero(void);
void	t_atoi(void);
void	t_itoa(void);

#endif