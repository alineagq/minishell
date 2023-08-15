/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 10:40:31 by fsuomins          #+#    #+#             */
/*   Updated: 2023/08/14 23:56:46 by fsuomins         ###   ########.fr       */
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

typedef struct s_cmd
{
	char			*cmd;
	char			*argv;
	struct s_cmd	*next;
}	t_cmd;

typedef struct s_config
{
	char	**env;
	char	*prompt;
	char	*parse;
	char	**raw_tokens;
	int		exit_code;
	int		state;
	t_cmd	*tokens;
}	t_config;

// UTILS
/**
 * Retrieves a pointer to the static configuration data structure.
 * This function returns a pointer to a statically allocated `t_config`
 * structure,
 * which is used to store program configuration and state information.
 * 
 * @return A pointer to the `t_config` data structure.
 */
t_config	*get_data(void);
/**
 * Free a dynamically allocated array of strings, including the strings
 * themselves.
 *
 * This function releases the memory used by an array of strings, where
 * each string is individually allocated, and then frees the memory of
 * the array itself.
 *
 * @param arr A pointer to an array of strings to be freed. The array
 * is terminated by a NULL pointer.
 */
void		free_char_array(char **arr);
void		free_cmd_list(t_cmd *head);
void		clear_data(t_config	*data);

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

// PROMPT
void		prompt(void);


// PARSE
char		*add_spaces(char *input);
int			is_delimiter(char c);
void		parse(void);
int			is_quote(char c);
char		**split_string_by_space(char *str);

// TOKENS
t_cmd		*create_tokens_cmd(char **raw_tokens);
int			str_is_command(char *str);
void		free_t_cmd(t_cmd *list);

// EXECUTE
// void		execute(void);

// EXIT
void		exit_program(void);

// PRINTS
void		print_char_array(char **arr);

#endif
