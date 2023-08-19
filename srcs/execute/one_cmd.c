/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_one_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 21:40:45 by viferrei          #+#    #+#             */
/*   Updated: 2023/08/18 23:35:39 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

// Returns 1 if a pipe operator is found.
int	has_pipe(t_tokens *tokens)
{
	t_tokens	*head;

	head = tokens;
	while (head)
	{
		if (head->type == OPTOKEN && !ft_strcmp(head->value, "|"))
			return (1);
		head = head->next;
	}
	return (0);
}

// Returns the function of the first builtin found.
int	exec_builtin(t_com *cmd, t_config *data, int original_fds[2])
{
	if (!cmd->sends_to_pipe && !cmd->receives_from_pipe)
	{
		if (handle_redirects(cmd, original_fds, data))
			return (restore_original_fds(original_fds));
	}
	if (!ft_strcmp(cmd->command, "echo"))
		return (builtin_echo(cmd->args));
	if (!ft_strcmp(cmd->command, "cd"))
		return (builtin_cd(cmd->args, cmd->envp, data));
	if (!ft_strcmp(cmd->command, "pwd"))
		return (builtin_pwd(cmd->args, cmd->envp, data));
	if (!ft_strcmp(cmd->command, "export"))
		return (builtin_export(cmd->args, data));
	if (!ft_strcmp(cmd->command, "unset"))
		return (builtin_unset(cmd->args, data));
	if (!ft_strcmp(cmd->command, "env"))
		return (builtin_env(cmd->args, cmd->envp, data->env_head));
	if (!ft_strcmp(cmd->command, "exit"))
		return (builtin_exit(cmd, cmd->args, cmd->envp, data));
	return (0);
}

// Handles single-command input - either builtin or not.
int	exec_one_cmd(t_com *cmd, t_config *data, int original_fds[2])
{
	if (data->issue_exit)
		return (data->issue_exit);
	if (cmd->is_builtin)
		data->exit_code = exec_builtin(cmd, data, original_fds);
	else
		data->exit_code = exec_com(cmd, data, original_fds);
	return (0);
}
