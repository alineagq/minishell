/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 15:15:27 by fsuomins          #+#    #+#             */
/*   Updated: 2023/08/14 23:56:17 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static t_cmd	*create_cmd(const char *cmd_str)
{
	t_cmd	*cmd;

	cmd = (t_cmd *)malloc(sizeof(t_cmd));
	if (!cmd)
		perror("malloc");
	else
	{
		cmd->cmd = ft_strdup(cmd_str);
		cmd->argv = NULL;
		cmd->next = NULL;
	}
	return (cmd);
}

static char	*cmd_argv_join(const char *arg1, const char *arg2)
{
	char	*joined;
	char	*new_arg;

	if (!arg1)
		return (ft_strdup(arg2));
	joined = ft_strjoin(arg1, " ");
	if (!joined)
		return (NULL);
	new_arg = ft_strjoin(joined, arg2);
	free(joined);
	return (new_arg);
}

static int	process_args(t_cmd *cmd, char **raw_tokens, int *index)
{
	char	*new_temp_arg;
	char	*new_arg;
	int		i;

	new_arg = NULL;
	i = *index + 1;
	while (raw_tokens[i] && !str_is_command(raw_tokens[i]))
	{
		new_arg = cmd_argv_join(cmd->argv, raw_tokens[i]);
		if (!new_arg)
			return (0);
		free(cmd->argv);
		cmd->argv = new_arg;
		new_temp_arg = cmd_argv_join(cmd->argv, raw_tokens[i]);
		if (!new_temp_arg)
			return (0);
		free(cmd->argv);
		cmd->argv = new_temp_arg;
		i++;
	}
	*index = i;
	return (1);
}

static t_cmd	*link_cmds(t_cmd *self, t_cmd *previous, t_cmd *temp)
{
	if (!self)
		self = temp;
	else
		previous->next = temp;
	return (self);
}


t_cmd	*create_tokens_cmd(char **raw_tokens)
{
	t_cmd	*self;
	t_cmd	*previous;
	t_cmd	*temp;
	int		i;

	if (!raw_tokens || !raw_tokens[0])
		return (NULL);
	self = NULL;
	previous = NULL;
	i = 0;
	while (raw_tokens[i])
	{
		temp = create_cmd(raw_tokens[i]);
		if (!temp || (raw_tokens[i + 1] && !process_args(temp, raw_tokens, &i)))
		{
			free_t_cmd(self);
			return (NULL);
		}
		self = link_cmds(self, previous, temp);
		previous = temp;
		i++;
	}
	return (self);
}
