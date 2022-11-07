/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 12:02:30 by gmasid            #+#    #+#             */
/*   Updated: 2022/11/07 18:42:01 by gmasid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

pid_t	get_pid(void)
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
	{
		throw_error(FORKERR, 1, NULL);
		exit(1);
	}
	if (pid == 0)
		exit(1);
	waitpid(pid, NULL, 0);
	return (pid - 1);
}

void	init_vars(t_data *data, char *program_name)
{
	int	i;

	(void)data;
	(void)program_name;
	data->envp = set_env("MYTEST", "123", data->envp);
	data->envp = set_env("MYTEST2", "12345", data->envp);
	data->envp = set_env("PATH", "12fdj3", data->envp);
	// TODO: Set PWD var to be "getcwd" return
	// TODO: Set SHLVL value if doesn't exists
	// TODO: Set PATH value if doesn't exists
	// TODO: Set _ value to be program_name var
}

t_data	init_data(char **argv, char **envp)
{
	t_data	result;

	result.cmds = NULL;
	result.envp = dup_matrix(envp);
	result.pid = get_pid();
	g_status = 0;
	init_vars(&result, argv[0]);
	return (result);
}

void	input_loop(char **argv, char **envp)
{
	t_data	data;
	char	*str;

	data = init_data(argv, envp);
	(void)data;
	while (1)
	{
		set_default_signal_handlers();
		str = readline("Minishell ▸ ");
		printf("command was %s\n", str);
		free(str);
	}
	free_matrix(data.envp);
}

int	minishell(char **argv, char **envp)
{
	input_loop(argv, envp);
	return (g_status);
}
