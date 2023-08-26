/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 10:40:31 by fsuomins          #+#    #+#             */
/*   Updated: 2023/08/26 02:47:01 by fsuomins         ###   ########.fr       */
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
# include <sys/stat.h>
# include <errno.h>
# include <fcntl.h>

# define LONG_MAX 9223372036854775807LL
# define LONG_MIN -9223372036854775808LL
# define EXEC_ERROR_CMD_NOT_FOUND 127
# define EXEC_ERROR_PERMISSION_DENIED 126

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
	int		splited_words;
	int		split_number;
	char	delimiter;
	int		size_of_word;
}	t_split_shell;

typedef struct s_config
{
	int			set_buffer_to_null;
	char		*oldpwd;
	t_env_list	*env;
	char		*prompt;
	char		*parse;
	char		**raw_tokens;
	int			exit_code;
	int			issue_exit;
	int			state;
	t_tokens	*tokens;
	int			tok_index;
	int			pipe_in[2];
	int			pipe_out[2];
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

void		init(void);// DONE
void		handler_int(int sig);
void		handle_eof(int signum);
void		set_signal(void);
void		sig_defaults(void);
void		ignore_signals(void);
t_env_list	*create_node(const char *key, const char *value);// DONE
t_env_list	*create_env_list(char **env);// DONE
void		set_env(t_env_list **head, const char *key, \
			const char *new_value);// DONE

// PROMPT

void		prompt(void);// DONE

// PARSE

void		parse(void);// DONE
char		*add_spaces(char *buffer, t_config *data);// DONE
char		**create_tokens_args(char *str, char delimiter);//	DONE
void		create_tokens(t_config *data);// DONE
void		expand_exit_code(t_config *data);// DONE
char		*find_exit_code(char *str);// DONE
void		expand_variables(t_config *data);// DONE
void		categorize_tokens(t_tokens *tokens);// DONE
void		remove_quotes_from_tokens(t_tokens *tokens);// DONE
void		iterate_through_quotes(t_split_shell *this);// DONE
int			check_for_non_print(char *value);
void		remove_invalid_redirections(t_tokens **head);// DONE
void		remove_empty_or_whitespace_nodes(t_tokens **head);// DONE
void		remove_end_spaces(t_config *data);// DONE
void		expand_tilde(t_config *data);// DONE

// EXECUTE
void		execute(void);
t_com		*get_exec_info(t_config *data);
char		*tok_command(t_config *data, t_com *self);
char		**tok_args(t_config *data);
t_reds		*tok_input(t_config *data);
t_reds		*tok_output(t_config *data);
char		**tok_envp(t_env_list *head);
int			exec_one_cmd(t_com *cmd, t_config *data, int original_fds[2]);
int			exec_builtin(t_com *cmd, t_config *data, int original_fds[2]);
int			has_pipe(t_tokens *tokens);
int			exec_multi(t_com *cmd, t_config *data, int original_fds[2]);
int			exec_fork_builtin(t_com *cmd, t_config *data, int original_fds[2]);
int			exec_com(t_com *cmd, t_config *data, int original_fds[2]);
int			handle_redirects(t_com *cmd, int original_fds[2], t_config *data);
int			redirect_heredoc(int original_fds[2], t_reds *in, t_config *data);
char		*heredoc(char *target, t_config *data);
void		*destroy_exec_info(t_com *self);
int			exec_com_multi(t_com *cmd, t_config *data, int original_fds[2]);
int			builtin_echo(char **args);
int			builtin_cd(char **args, char **envp, t_config *data);
int			builtin_env(char **args, char **envp, t_env_list *env_list);
int			builtin_exit(t_com *cmd, char **args, char **envp, t_config *data);
int			builtin_export(char	**args, t_com *com, t_config *data);
int			builtin_pwd(char **args, char **envp, t_config *data);
int			builtin_unset(char **args, t_com *com, t_config *data);
char		*heredoc_handle_expansions(char *str, t_config *data);
char		*tok_get_path(char *value, t_env_list *env_head);
void		compare_arg_env(t_env_list **head, const char *key);
int			exec_loop(t_com *cmd, t_config *data, int original_fds[2]);
void		initialize(t_config **data, int *original_fds);
int			executionLoop(t_config *data, int *original_fds);
void		finalize(t_config *data);
void		create_redirect_files(t_com *cmd);

// EXIT

void		exit_program(void);
void		*safe_free(void *content);// DONE
void		clear_env(t_config *data);// DONE
void		free_char_array(char **arr);// DONE
void		free_tokens(t_tokens *tokens);// DONE

// UTILS

t_config	*get_data(void);
void		clear_data(t_config	*data);// DONE
int			restore_original_fds(int original_fds[2]);
void		*free_pp_char(char **pp);
int			is_variable(char c);//	DONE
char		*find_variable(char	*str);// DONE
char		*get_var_name(char	*var_head);
char		*get_env_value(t_env_list *head, char *targetKey);// DONE
void		print_env_list(t_env_list *head);
int			is_delimiter(char c);// DONE
void		count_words(t_split_shell *this);
int			get_token_type(t_tokens *temp);// DONE
int			token_is_error(t_tokens *temp);//	DONE
int			token_is_builtin(char *value);
int			token_is_operator(char *value);// DONE
int			token_is_redirect(char *value);// DONE
int			token_is_word(t_tokens *temp);
int			token_is_command(t_tokens *temp);
int			token_is_fd(t_tokens *temp);//	DONE
t_tokens	*iterate_to_tok_index(t_config *data);
t_reds		*create_red_list(int nodes);
int			write_to_heredoc(int ret_fd, char *target, t_config *data);
char		*get_home_dir_from_envs(t_config *data);
int			update_oldpwd(t_config *data, char *curr_path);
int			update_pwd(t_config *data, char *path);
char		*expand_home(char *path, t_config *data);
int			count_args(char **args);
int			cd_error_args(t_config *data);

void		close_inherited_fds(void);
void		print_export_list(t_env_list *head);

#endif