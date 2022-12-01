/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucafern <lucafern@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 13:21:49 by lucafern          #+#    #+#             */
/*   Updated: 2022/12/01 14:35:43 by lucafern         ###   ########.fr       */
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

	i = 1;
	curr_node = data->cmds;
	while (curr_node)
	{
		curr = curr_node->content;
		define_cmd_path(curr, data);
		run_cmd(curr->cmd_path, curr->full_cmd, NULL);
		curr_node = curr_node->next;
		i++;
	}
}
