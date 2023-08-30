/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 10:40:31 by fsuomins          #+#    #+#             */
/*   Updated: 2023/08/30 18:54:41 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libs/libft.h"
# include <errno.h>
# include <fcntl.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <stdio.h>
# include <sys/wait.h>
# include <unistd.h>

# define ERR 0
# define INIT 1
# define PROMPT 2
# define PARSE 3
# define EXECUTE 4
# define EXIT 5

typedef struct s_config
{
	char			**env;
	char			*str;
	char			*parse;
	char			**raw_tokens;
	int				interactive_mode;
	int				state;
	t_cmd			*tokens;

}					t_config;

typedef struct s_cmd
{
	char			*cmd;
	char			**argv;
	t_cmd			*next;
}					t_cmd;

typedef struct s_env
{
	char			*key;
	char			*value;
	struct env_list	*next;
}					t_env;

// DATA
t_config			*get_data(void);

// INIT
void				init(void);
void				set_signal(void);
void				handler_int(int sig);
void				handle_eof(int signum);

// PROMPT
char				*read_line(void);
void				prompt(void);

// PARSE
char				*add_spaces(char *input);
int					is_delimiter(char c);
void				parse(void);
int					is_quote(char c);
char				**split_string_by_space(char *str);

//
void				print_char_array(char **arr);
void				free_char_array(char **arr);

// ENV
t_env				*create_env_list(char **env);
void				set_env(t_env **head, const char *key,
						const char *new_value);
t_env				*create_node(const char *key, const char *value);
#endif
