/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqueiroz <aqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 03:26:39 by aqueiroz          #+#    #+#             */
/*   Updated: 2023/07/22 00:14:39 by aqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

int counter = 0;
int error = 0;
int sucess = 0;
char **stringArray = NULL;
int arraySize = 0;

void init_report(void)
{
    counter = 0;
    error = 0;
    sucess = 0;
    stringArray = NULL;
    arraySize = 0;
}

void	clear_report(void)
{
	counter = 0;
	error = 0;
	sucess = 0;
	arraySize = 0;
}

void	print_report(void)
{
	if (counter != 0)
	{
		if (error == 0)
			printf("\n\033[32m\u2714\033[0m Sucess! ");
		else
			printf("\n\033[31m\u2717\033[0m Founded %d errors. ", error);
		printf("%d/%d (%d%%)\n", sucess, counter, (sucess * 100) / counter);
	}
}

void	error_log(void)
{
	if (stringArray == NULL)
		return ;
	for (int i = 0; i < arraySize; i++)
	{
		if (stringArray[i] != NULL)
		{
			printf("\033[37mError %d: %s\n\033[0m", i + 1, stringArray[i]);
			free(stringArray[i]);
		}
	}
	free(stringArray);
	stringArray = NULL;
}

void	report(void)
{
	print_report();
	error_log();
	clear_report();
}
