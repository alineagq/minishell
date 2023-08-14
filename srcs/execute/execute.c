/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 18:49:30 by fsuomins          #+#    #+#             */
/*   Updated: 2023/08/13 22:49:03 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

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

#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

void execute_cmd_list(const t_config *data) {
    pid_t pid = fork();

    if (pid < 0) {
        perror("fork");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        // Child process
        char *args[3];
        args[0] = ft_strdup(data->tokens->cmd);
        args[1] = ft_strdup(data->tokens->argv);
        args[2] = NULL;

        execve("/bin/echo", args, data->env);
        
        // If execve fails, we should exit the child process with an error
        perror("execve");
        exit(EXIT_FAILURE);
    } else {
        // Parent process        
        int status;
        waitpid(pid, &status, 0);

        if (WIFEXITED(status)) {
            fprintf(stdout, "Child process exited with status: %d\n", WEXITSTATUS(status));
        } else if (WIFSIGNALED(status)) {
            fprintf(stdout, "Child process terminated due to signal: %d\n", WTERMSIG(status));
        }
    }
}




void execute(void) {
    t_config *data = get_data();
    execute_cmd_list(data);
    if (data->state == EXECUTE) {
        data->state = PROMPT;
    }
}

