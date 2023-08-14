/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 15:15:27 by fsuomins          #+#    #+#             */
/*   Updated: 2023/08/12 18:33:45 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	free_t_cmd(t_cmd *list)
{
	t_cmd	*temp;

	while (list)
	{
		temp = list;
		list = list->next;
		free(temp->cmd);
		free(temp->argv);
		free(temp);
	}
}

void	print_t_cmd(t_cmd *list)
{
	while (list)
	{
		printf("Command:%s\n", list->cmd);
		printf("Arguments:%s\n", list->argv);
		list = list->next;
	}
}

int str_is_command(char *str)
{
  return (strcmp(str, "|") == 0 || strcmp(str, ";") == 0 || strcmp(str, "<") == 0
          || strcmp(str, ">") == 0 || strcmp(str, "<<") == 0 || strcmp(str, ">>") == 0);
}


t_cmd *create_tokens_cmd(char **raw_tokens)
{
    int i = 0;
    t_cmd *self = NULL;
    t_cmd *temp = NULL;
    t_cmd *previous = NULL;
	char *new_arg = NULL;

    if (!raw_tokens || !raw_tokens[0])
        return NULL;

    while (raw_tokens[i])
    {
        temp = (t_cmd *)malloc(sizeof(t_cmd));
        if (!temp)
        {
            perror("malloc");
            free_t_cmd(self); // Free any previously allocated memory
            return NULL;
        }
        temp->cmd = ft_strdup(raw_tokens[i]);
        temp->argv = NULL;

        if (raw_tokens[i + 1] && !str_is_command(raw_tokens[i + 1]))
        {
            i++;
            while (raw_tokens[i] && !str_is_command(raw_tokens[i]))
            {
				if (temp->argv == NULL)
					new_arg = ft_strjoin(temp->argv, "");
				else
					new_arg = ft_strjoin(temp->argv, " ");
                if (!new_arg)
                {
                    perror("malloc");
                    free_t_cmd(self); // Free any previously allocated memory
                    return NULL;
                }
                free(temp->argv);
                temp->argv = new_arg;

                char *new_temp_arg = ft_strjoin(temp->argv, raw_tokens[i]);
                if (!new_temp_arg)
                {
                    perror("malloc");
                    free_t_cmd(self); // Free any previously allocated memory
                    return NULL;
                }
                free(temp->argv);
                temp->argv = new_temp_arg;

                i++;
            }
        }

        temp->next = NULL;
        if (self == NULL)
            self = temp;
        else
            previous->next = temp;

        previous = temp;
        i++;
    }

    return self;
}

