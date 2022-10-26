/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 13:49:30 by gmasid            #+#    #+#             */
/*   Updated: 2022/10/25 19:47:52 by gmasid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	free_pointer_and_contents(char **ptr)
{
	int	i;

	i = 0;
	while (ptr[i])
		free(ptr[i++]);
	free(ptr);
}

char	*find_path(char *cmd, char **envp)
{
	int		i;
	char	**paths;
	char	*part_path;
	char	*cmd_path;

	i = 0;
	while (ft_strnstr(envp[i], "PATH", 4) == 0)
		i++;
	paths = ft_split(envp[i] + 5, ':');
	i = 0;
	while (paths[i])
	{
		part_path = ft_strjoin(paths[i], "/");
		cmd_path = ft_strjoin(part_path, cmd);
		free(part_path);
		if (access(cmd_path, F_OK) == 0)
		{
			free_pointer_and_contents(paths);
			return (cmd_path);
		}
		i++;
	}
	free_pointer_and_contents(paths);
	return (cmd);
}

void	run_cmd(char *path, char **cmd, char **env)
{
	pid_t	pid;

	pid = fork();
	if (pid == 0)
	{
		execve(path, cmd, env);
		perror("Error");
		exit(127);
	}
	waitpid(pid, NULL, 0);
}

void	execute_bin(char **args, char **envp)
{
	char	*path;

	if (str_ichr(args[0], '/') > -1)
		path = args[0];
	else
		path = find_path(args[0], envp);
	run_cmd(path, args, envp);
}