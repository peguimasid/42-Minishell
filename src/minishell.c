/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 12:02:30 by gmasid            #+#    #+#             */
/*   Updated: 2022/12/07 13:59:33 by gmasid           ###   ########.fr       */
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
	init_pwd(data);
	init_shlvl(data);
	init_path(data);
	init_executable(data, program_name);
}

t_data	init_data(char **argv, char **envp)
{
	t_data	result;

	result.input = NULL;
	result.cmds = NULL;
	result.running = 1;
	result.envp = dup_matrix(envp);
	// result.pid = get_pid();
	g_status = 0;
	init_vars(&result, argv[0]);
	return (result);
}

void	input_loop(t_data *data)
{
	clear_window();
	while (data->running)
	{
		set_default_signal_handlers();
		data->input = readline("Minishell ▸ ");
		if (!handle_input(data))
			data->running = 0;
	}
}

int	minishell(char **argv, char **envp)
{
	t_data	data;

	data = init_data(argv, envp);
	input_loop(&data);
	free_data(&data);
	return (g_status);
}
