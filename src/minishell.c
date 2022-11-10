/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 12:02:30 by gmasid            #+#    #+#             */
/*   Updated: 2022/11/10 17:54:07 by gmasid           ###   ########.fr       */
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
	char	*shlvl;
	char	*aux;

	aux = getcwd(NULL, 0);
	data->envp = set_env("PWD", aux, data->envp);
	free(aux);
	aux = get_env("SHLVL", data->envp);
	if (!aux || ft_atoi(aux) <= 0)
		shlvl = ft_strdup("1");
	else
		shlvl = ft_itoa(ft_atoi(aux) + 1);
	data->envp = set_env("SHLVL", shlvl, data->envp);
	free(shlvl);
	aux = get_env("PATH", data->envp);
	if (!aux)
		data->envp = set_env("PATH", DEFAULT_PATH, data->envp);
	aux = get_env("_", data->envp);
	if (!aux)
		data->envp = set_env("_", program_name, data->envp);
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
	while (data->running)
	{
		set_default_signal_handlers();
		data->input = readline("Minishell ▸ ");
		printf("command was %s\n", data->input);
		free(data->input);
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
