/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 17:31:19 by gmasid            #+#    #+#             */
/*   Updated: 2022/10/24 13:59:30 by gmasid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	main(int argc, char **argv, char **env)
{
	pid_t	pid;

	(void)argc;
	(void)env;
	pid = fork();
	if (pid == 0)
		execve("/bin/ls", argv, NULL);
	waitpid(pid, NULL, 0);
	sleep(1);
	printf("I've continue running even after execve");
}
