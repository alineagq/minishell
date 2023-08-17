/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 10:40:31 by fsuomins          #+#    #+#             */
/*   Updated: 2023/08/17 18:22:21 by fsuomins         ###   ########.fr       */
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
typedef struct s_cmd
{
	char			*cmd;
	char			*argv;
	struct s_cmd	*next;
}	t_cmd;

typedef struct env_list
{
	char			*key;
	char			*value;
	struct env_list	*next;
}	t_env_list;

typedef struct s_config
{
	int			set_buffer_to_null;
	t_env_list	*env;
	char		*prompt;
	char		*parse;
	char		**raw_tokens;
	int			exit_code;
	int			state;
	t_cmd		*tokens;
	pid_t		*child_pids;
	int			pipe[2];
	int			fd[2];
	int			num_child_pids;
}	t_config;

// UTILS
t_config	*get_data(void);
void		free_char_array(char **arr);
void		free_cmd_list(t_cmd *head);
void		clear_data(t_config	*data);
char		*get_env_value(char *env, char **envp);
void		set_env(t_config *data, char *env, char *value);
int			count_env(char **env);
t_env_list	*create_env_list(char **env);
void		add_env(char *var, char *value, t_config *data);
t_env_list	*create_env_list(char **env);
void		print_env_list(t_env_list *head);
char		*get_value_env(t_env_list *head, const char *key);
void update_or_insert_value(t_env_list **head, const char *key, const char *new_value);

// INIT

/**
 * Initialize configuration data and environment variables.
 * This function sets up signal handling, creates a copy of the
 * environment variables, and updates the configuration
 * state to PROMPT.
 */
void		init(void);
void		set_signal(void);
void		handler_int(int sig);
void		handle_eof(int signum);
void cleanup();

// PROMPT
void		prompt(void);


// PARSE
void	*safe_free(void *content);
int			is_delimiter(char c);
char		*add_spaces(char *buffer, t_config *ms);
void		parse(void);
int			is_quote(char c);
char		**split_string_by_space(char *str);

// TOKENS
t_cmd		*create_tokens_cmd(char **raw_tokens);
int			str_is_command(char *str);
void		free_t_cmd(t_cmd *list);

// EXECUTE
void		execute(void);

// EXIT
void		exit_program(void);

// PRINTS
void		print_char_array(char **arr);
void print_structs(t_config *config);
void close_inherited_fds(int preserve_fds[]);

#endif
