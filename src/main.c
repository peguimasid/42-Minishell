/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucafern <lucafern@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 17:31:19 by gmasid            #+#    #+#             */
/*   Updated: 2022/10/25 15:38:51 by lucafern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	main(int argc, char *argv[])
{
	char	*line;

	while (1 || argc)
	{
		line = readline("Minishell ▸ ");
		printf("command was: %s\n", line);
		if (strcmp(line, "test") == 0)
		{
			if (fork() == 0)
				execve("a.out", argv, NULL);
			wait(0);
		}
	}
}
