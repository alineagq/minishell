/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 09:58:56 by fsuomins          #+#    #+#             */
/*   Updated: 2023/08/17 01:13:56 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void print_structs(t_config *config)
{
    if (config != NULL)
    {
        if (config->env != NULL)
            printf("env: %s\n", *(config->env));
        if (config->prompt != NULL)
            printf("prompt: %s\n", config->prompt);
        if (config->parse != NULL)
            printf("parse: %s\n", config->parse);
        if (config->raw_tokens != NULL)
            printf("raw_tokens: %s\n", *(config->raw_tokens));
        printf("exit_code: %d\n", config->exit_code);
        printf("state: %d\n", config->state);
        printf("num_child_pids: %d\n", config->num_child_pids);
        printf("pipe: %d, %d\n", config->pipe[0], config->pipe[1]);

        t_cmd *cmd = config->tokens;
        while (cmd != NULL)
        {
            if (cmd->cmd != NULL)
                printf("cmd: %s\n", cmd->cmd);
            if (cmd->argv != NULL)
                printf("argv: %s\n", cmd->argv);
            cmd = cmd->next;
        }

        pid_t *pids = config->child_pids;
        for (int i = 0; i < config->num_child_pids; i++)
        {
            printf("child_pid: %d\n", pids[i]);
        }
    }
    else
    {
        printf("The struct t_config is NULL.\n");
    }
}
/**
 * Checks the validity of command line arguments.
 * Exits with status 1 if the argument count is not 1.
 * 
 * @param argc The argument count.
 * @param argv The array of command line arguments.
 */
static	void	is_valid(int argc, char **argv)
{
	(void)argv;
	if (argc != 1)
		return (exit(1));
}

/**
 * Entry point of the program.
 * Manages the execution flow based on the state of the data.
 * 
 * @param argc The argument count.
 * @param argv The array of command line arguments.
 * @return Returns 0 to indicate successful program execution.
 */
int	main(int argc, char **argv)
{
	t_config	*data;	

	is_valid(argc, argv);
	data = get_data();
	data->state = INIT;
	while (1)
	{
		if (data->state == INIT)
			init();
		if (data->state == PROMPT)
			prompt();
		if (data->state == PARSE)
		{
			parse();
			// print_structs(data);
		}
		if (data->state == EXECUTE)
			execute();
		if (data->state == EXIT)
			exit_program();
	}
	return (0);
}
