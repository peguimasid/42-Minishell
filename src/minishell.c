/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 12:02:30 by gmasid            #+#    #+#             */
/*   Updated: 2022/11/05 12:41:39 by gmasid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	input_loop(void)
{
	char	*str;

	while (1)
	{
		str = readline("$");
		printf("command was %s\n", str);
		free(str);
	}
}

void	minishell(int argc, char **argv, char **envp)
{
	(void)argv;
	(void)envp;
	if (argc != 1)
		throw_error("Don't provider arguments");
	signal(SIGINT, handle_sigint);
	signal(SIGQUIT, SIG_IGN);
	input_loop();
	exit(g_status);
}
