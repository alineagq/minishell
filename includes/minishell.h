/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 10:40:31 by fsuomins          #+#    #+#             */
/*   Updated: 2023/08/19 01:59:34 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# ifndef _LINUX_LIMITS_H
#  define _LINUX_LIMITS_H
#  define PATH_MAX		4096
#  define PIPE_BUF		4096
# endif

# include "../libs/libft.h"
# include <readline/readline.h>
# include <readline/history.h>
# include <stdio.h>
# include <signal.h>
# include <unistd.h>
# include <sys/wait.h>
# include <errno.h>
# include <fcntl.h>
# include "init.h"

# define ERR 		0
# define INIT 		1
# define PROMPT 	2
# define PARSE 		3
# define EXECUTE 	4
# define EXIT 		5
# define FREE	 	6

# define ERRTOKEN		-1
# define COMTOKEN		0
# define BITOKEN		1
# define WORDTOKEN		2
# define OPTOKEN		3
# define REDTOKEN		4
# define FDTOKEN		5

# define NOPE			0
# define HEREDOC		1
# define INFILE			2
# define OVERWRITE		3
# define APPEND			4
# define NO_REDIRECT	-1

typedef struct s_tokens
{
	char			*value;
	int				type;
	int				index;
	struct s_tokens	*next;
	struct s_tokens	*prev;
}	t_tokens;

typedef struct env_list
{
	char			*key;
	char			*value;
	struct env_list	*next;
}	t_env_list;

typedef struct s_split_shell
{
	char	*string;
	char	*temp;
	int		words;
	int		i;
	int		split_number;
	char	delimiter;
	int		sz;
}	t_split_shell;

typedef struct s_config
{
	int			set_buffer_to_null;
	t_env_list	*env;
	char		*prompt;
	char		*parse;
	char		**raw_tokens;
	int			exit_code;
	int			issue_exit;
	int			state;
	t_tokens	*tokens;
	int			tok_index;
}	t_config;

typedef struct s_reds
{
	int				type;
	char			*target;
	struct s_reds	*next;
}	t_reds;

typedef struct s_com
{
	int				block_exec;
	char			*command;
	int				is_builtin;
	char			**args;
	char			**envp;
	struct s_reds	*red_in;
	struct s_reds	*red_out;
	int				receives_from_pipe;
	int				sends_to_pipe;
	char			*error_to_print;
}	t_com;

// INIT

void		init(void);
void		handler_int(int sig);
void		handle_eof(int signum);
void		set_signal(void);
t_env_list	*create_node(const char *key, const char *value);
t_env_list	*create_env_list(char **env);

// PROMPT

void		prompt(void);

// PARSE

void		parse(void);
char		*add_spaces(char *buffer, t_config *data);
char		**ft_split_shell(char *str, char delimiter);
void		create_tokens(t_config *data);
void		expand_exit_code(t_config *data);
void		expand_variables(t_config *data);
void		categorize_tokens(t_tokens *tokens);
void		remove_quotes_from_tokens(t_tokens *tokens);

// EXECUTE

t_com		*get_exec_info(t_config *data);
char		*tok_command(t_config *data, t_com *self);
char		**tok_args(t_config *data);
t_reds		*tok_input(t_config *data);
t_reds		*tok_output(t_config *data);

#endif