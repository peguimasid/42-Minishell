/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucafern <lucafern@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 15:27:56 by gmasid            #+#    #+#             */
/*   Updated: 2022/12/09 20:18:06 by lucafern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/minishell.h"

int	execute_command_in_child_process(t_list *node, t_data *data)
{
	t_cmd	*cmd;

	cmd = node->content;
	set_child_process_signal_handlers();
	if (is_generate_output_builtin(cmd))
		return (handle_generate_output_builtin(node, data));
	execve(cmd->cmd_path, cmd->full_cmd, data->envp);
	return (1);
}

void	handle_child_process(t_list *node, t_data *data, int fd[2])
{
	handle_redirections(node, fd);
	close(fd[READ_END]);
	execute_command_in_child_process(node, data);
	ft_lstclear(&data->cmds, free_node);
	free_matrix(data->args);
	free_matrix(data->envp);
	exit(g_status);
}

void	handle_execution(t_list *node, t_data *data, int fd[2])
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
	{
		close(fd[READ_END]);
		close(fd[WRITE_END]);
		throw_error(FORKERR, 1, NULL);
	}
	if (pid == 0)
	{
		handle_child_process(node, data, fd);
	}
}

void	execute(t_list *node, t_data *data, int fd[2])
{
	t_cmd	*cmd;

	cmd = node->content;
	if (cmd->infile == -1 || cmd->outfile == -1)
		return ;
	if (can_execute_in_child_process(cmd))
		handle_execution(node, data, fd);
}
