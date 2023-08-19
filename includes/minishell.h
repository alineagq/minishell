/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 10:40:31 by fsuomins          #+#    #+#             */
/*   Updated: 2023/08/18 23:20:59 by fsuomins         ###   ########.fr       */
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

typedef struct s_tokens
{
	char			*value;
	int				type;
	int				index;
	struct s_tokens	*next;
	struct s_tokens	*prev;
}				t_tokens;

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
	int			state;
	t_tokens	*tokens;
}	t_config;

// INIT
void		init(void);
void		set_signal(void);
void		handler_int(int sig);
void		handle_eof(int signum);

// PROMPT
void		prompt(void);

// PARSE
void		parse(void);
char		*add_spaces(char *buffer, t_config *ms);
void		iterate_through_quotes(t_split_shell *this);
char		**ft_split_shell(char *str, char delimiter);
void		create_tokens(t_config *data);
void		expand_exit_code(t_config *data);
void		expand_variables(t_config *data);
void		categorize_tokens(t_tokens *tokens);
void		remove_quotes_from_tokens(t_tokens *tokens);


// EXECUTE
void		execute(void);

// ENVS
void		print_env_list(t_env_list *head);
t_env_list	*create_env_list(char **env);
void		set_env(t_env_list **head, const char *key, const char *new_value);

// EXIT
void		cleanup(void);
void		exit_program(void);

// UTILS
t_config	*get_data(void);
void		clear_data(t_config	*data);

void		add_node(t_env_list **head, t_env_list **cur, t_env_list *new);
t_env_list	*create_node(const char *key, const char *value);
void		update_value(t_env_list *node, const char *new_value);
void		insert_node(t_env_list **head, t_env_list *prev, t_env_list *new);
char		*get_env_value(t_env_list *head, char *targetKey);

void		close_inherited_fds(void);

void		free_tokens(t_tokens *tokens);
void		free_char_array(char **arr);
void		clear_env(t_config *data);
void		*safe_free(void *content);

int			get_token_type(t_tokens *temp);
int			token_is_error(t_tokens *temp);
int			token_is_fd(t_tokens *temp);

int			token_is_builtin(char *value);
int			token_is_operator(char *value);
int			token_is_redirect(char *value);
int			token_is_word(t_tokens *temp);
int			token_is_command(t_tokens *temp);
int			check_for_non_print(char *value);

int			is_delimiter(char c);
void		count_words(t_split_shell *this);

char		*find_variable(char	*str);
int			is_variable(char c);

#endif