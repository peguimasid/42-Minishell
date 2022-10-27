/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_handler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucafern <lucafern@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 15:54:10 by lucafern          #+#    #+#             */
/*   Updated: 2022/10/25 16:47:02 by lucafern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	builtin_handler(char *line, char *argv[])
{
	char	**command;

	command = ft_split(line, ' ');
	if (strcmp(command[0], "test") == 0)
	{
		if (fork() == 0)
			execve("a.out", argv, NULL);
		wait(0);
	}
	else if (strcmp(command[0], "pwd") == 0)
		pwd();
	else if (strcmp(command[0], "cd") == 0)
		cd(command);
	else
		printf("Command not found\n");
}
