/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 12:02:30 by gmasid            #+#    #+#             */
/*   Updated: 2022/11/05 20:59:05 by gmasid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

pid_t	get_pid(void)
{
	pid_t	pid;

	pid = fork();
	if (pid == 0)
		exit(1);
	waitpid(pid, NULL, 0);
	return (pid - 1);
}

t_data	init_data(char **argv, char **envp)
{
	t_data	result;

	(void)argv;
	result.cmds = NULL;
	result.envp = dup_matrix(envp);
	result.pid = get_pid();
	g_status = 0;
	// TODO: init necessary vars if dont exits (PWD, SHLVL, PATH, _)
	return (result);
}

void	input_loop(char **argv, char **envp)
{
	char	*str;
	t_data	data;

	data = init_data(argv, envp);
	printf("pid = %d\n", data.pid);
	while (1)
	{
		str = readline("Minishell ▸ ");
		printf("command was %s\n", str);
		free(str);
	}
}

void	minishell(int argc, char **argv, char **envp)
{
	if (argc != 1)
		throw_error("Don't provide arguments");
	signal(SIGINT, handle_sigint);
	signal(SIGQUIT, SIG_IGN);
	input_loop(argv, envp);
	exit(g_status);
}
