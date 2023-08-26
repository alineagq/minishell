/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   com.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 21:15:32 by coder             #+#    #+#             */
/*   Updated: 2023/08/26 01:03:41 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

static pid_t	create_child(void)
{
	pid_t	child_pid;

	child_pid = fork();
	if (child_pid < 0)
	{
		write(2, "error: Can't spawn child\n", 25);
		exit(-1);
	}
	return (child_pid);
}

int	get_exec_error(char *path, t_config *data)
{
	struct stat	sb;

	if (stat(path, &sb) == 0 && S_ISDIR(sb.st_mode))
	{
		data->exit_code = 126;
		ft_putstr_fd("Is a directory\n", STDERR_FILENO);
	}
	if (!path)
		data->exit_code = 1;
	else if (access(path, X_OK))
	{
		data->exit_code = 127;
		ft_putstr_fd(path, STDERR_FILENO);
		ft_putstr_fd(": command not found\n", STDERR_FILENO);
	}
	return (data->exit_code);
}

int	pipe_handle(t_config *data, t_com *cmd)
{
	if (cmd->receives_from_pipe)
	{
		close(data->pipe_in[1]);
		dup2(data->pipe_in[0], STDIN_FILENO);
	}
	if (cmd->sends_to_pipe)
	{
		close(data->pipe_out[0]);
		dup2(data->pipe_out[1], STDOUT_FILENO);
	}
	return (0);
}

int	exec_fork_builtin(t_com *cmd, t_config *data, int original_fds[2])
{
	int	pid;

	pid = create_child();
	if (!pid)
	{
		sig_defaults();
		pipe_handle(data, cmd);
		if (handle_redirects(cmd, original_fds, data))
		{
			data->issue_exit = -1;
			return (restore_original_fds(original_fds));
		}
		data->issue_exit = -1;
		return (exec_builtin(cmd, data, original_fds));
	}
	return (data->exit_code);
}

int	exec_com(t_com *cmd, t_config *data, int original_fds[2])
{
	int		pid;

	pid = create_child();
	if (!pid)
	{
		data->exit_code = 0;
		if (!get_exec_error(cmd->command, data))
		{
			sig_defaults();
			if (handle_redirects(cmd, original_fds, data))
			{
				data->issue_exit = -1;
				return (restore_original_fds(original_fds));
			}
			execve(cmd->command, cmd->args, cmd->envp);
		}
		else
			data->issue_exit = -1;
		return (data->exit_code);
	}
	return (data->exit_code);
}

int	exec_com_multi(t_com *cmd, t_config *data, int original_fds[2])
{
	int		pid;

	pid = create_child();
	if (!pid)
	{
		data->exit_code = 0;
		if (!get_exec_error(cmd->command, data))
		{
			sig_defaults();
			pipe_handle(data, cmd);
			if (handle_redirects(cmd, original_fds, data))
			{
				data->issue_exit = -1;
				return (restore_original_fds(original_fds));
			}
			execve(cmd->command, cmd->args, cmd->envp);
		}
		else
			data->issue_exit = -1;
		return (data->exit_code);
	}
	close(data->pipe_in[0]);
	close(data->pipe_in[1]);
	return (data->exit_code);
}
