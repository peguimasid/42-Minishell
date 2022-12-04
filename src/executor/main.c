/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucafern <lucafern@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 13:21:49 by lucafern          #+#    #+#             */
/*   Updated: 2022/12/04 15:27:04 by lucafern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	run_cmd(char *path, char **cmd, char **env)
{
	execve(path, cmd, env);
	perror("Error");
	exit(127);
}

void	end_cmds(t_data *data, int (*fd)[2], int *pid)
{
	int	i;

	i = 0;
	while (i < ft_lstsize(data->cmds) && ft_lstsize(data->cmds) > 1)
	{
		close(fd[i][0]);
		close(fd[i][1]);
		i++;
	}
	i = 0;
	while (i < ft_lstsize(data->cmds))
		waitpid(pid[i++], NULL, 0);
}

void	loop_cmds(t_list *curr_node, int (*fd)[2], int *pid, t_data *data)
{
	int		i;
	t_cmd	*curr;

	i = 0;
	while (i < ft_lstsize(data->cmds))
	{
		if (pipe(fd[i]) < 0)
			return ;
		pid[i] = fork();
		if (pid[i] < 0)
			return ;
		if (pid[i] == 0)
		{
			curr = curr_node->content;
			define_cmd_path(curr, data);
			if (i > 0)
				read_from_prev_pipe(fd[i - 1]);
			if (i < ft_lstsize(data->cmds) - 1)
				write_on_pipe_to_next_cmd(fd[i], ft_lstsize(data->cmds));
			run_cmd(curr->cmd_path, curr->full_cmd, data->envp);
			return ;
		}
		curr_node = curr_node->next;
		i++;
	}
}

void	handle_cmds(t_data *data)
{
	t_list	*curr_node;
	int		fd[4096][2];
	int		pid[4096];

	curr_node = data->cmds;
	loop_cmds(curr_node, fd, pid, data);
	end_cmds(data, fd, pid);
}
