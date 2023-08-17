/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 10:40:31 by fsuomins          #+#    #+#             */
/*   Updated: 2023/08/11 11:35:00 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libs/libft.h"
# include <readline/readline.h>
# include <readline/history.h>
# include <stdio.h>
# include <signal.h>
# include <unistd.h>
# include <sys/wait.h>
# include <errno.h>
# include <fcntl.h>

# define ERR 	0
# define INIT 	1
# define PROMPT 2
# define PARSE 	3

typedef struct s_config
{
	char	**env;
	char	*str;
	char	*parse;
	char	**raw_tokens;
	int		interactive_mode;
	int		state;
	t_list	*tokens;

}	t_config;

typedef struct s_list
{
	char	*cmd;
	char	**argv;
	t_list	*next;
}t_list;

// UTILS
t_config	*get_data(void);

// INIT
void		init(void);
void		set_signal(void);
void		handler_int(int sig);
void		handle_eof(int signum);

// PROMPT
char		*read_line(void);
void		prompt(void);

// PARSE
char		*add_spaces(char *input);
int			is_delimiter(char c);
void		parse(void);
int			is_quote(char c);
char		**split_string_by_space(char *str);

//
void		print_char_array(char **arr);
void		free_char_array(char **arr);
#endif
