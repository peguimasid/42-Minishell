/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 12:02:30 by gmasid            #+#    #+#             */
/*   Updated: 2022/11/05 14:40:07 by gmasid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_data	init_data(char **argv, char **envp)
{
	t_data	result;

	(void)argv;
	result.cmds = NULL;
	result.envp = dup_matrix(envp);
	g_status = 0;
	// get pid
	return (result);
}

void	input_loop(char **argv, char **envp)
{
	char	*str;
	t_data	data;

	data = init_data(argv, envp);
	while (1)
	{
		str = readline("$");
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
