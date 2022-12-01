/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucafern <lucafern@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 13:21:49 by lucafern          #+#    #+#             */
/*   Updated: 2022/12/01 18:04:23 by lucafern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	str_ichr(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	if (str[i] == c)
		return (i);
	return (-1);
}

void	run_cmd(char *path, char **cmd, char **env)
{
	execve(path, cmd, env);
	perror("Error");
	exit(127);
}

void	define_cmd_path(t_cmd *cmd, t_data *data)
{
	if (str_ichr(cmd->full_cmd[0], '/') > -1)
		cmd->cmd_path = cmd->full_cmd[0];
	else
		cmd->cmd_path = find_cmd_path(data, cmd->full_cmd[0]);
}

void	handle_cmds(t_data *data)
{
	int		i;
	t_cmd	*curr;
	t_list	*curr_node;
	int		fd[4096][2];
	int		pid[4096];
	int		lst_size;

	i = 0;
	curr_node = data->cmds;
	lst_size = ft_lstsize(data->cmds);
	while (i < lst_size)
	{
		if (pipe(fd[i]) < 0)
			return ;
		pid[i] = fork();
		curr = curr_node->content;
		define_cmd_path(curr, data);
		if (pid[i] < 0)
			return ;
		if (pid[i] == 0)
		{
			if (i > 0)
				waitpid(pid[i - 1], NULL, 0);
			if (i > 0)
			{
				dup2(fd[i - 1][0], STDIN_FILENO);
				close(fd[i - 1][0]);
				close(fd[i - 1][1]);
				run_cmd(curr->cmd_path, curr->full_cmd, data->envp);
			}
			if (i < lst_size)
			{
				if (lst_size > 1)
				{
					dup2(fd[i][1], STDOUT_FILENO);
					close(fd[i][0]);
					close(fd[i][1]);
				}
				run_cmd(curr->cmd_path, curr->full_cmd, data->envp);
			}
			return ;
		}
		curr_node = curr_node->next;
		i++;
	}
	i = 0;
	while (i < ft_lstsize(data->cmds))
	{
		close(fd[i][0]);
		close(fd[i][1]);
		i++;
	}
	i = 0;
	while (i < ft_lstsize(data->cmds))
	{
		waitpid(pid[i++], NULL, 0);
	}
}
