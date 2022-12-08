/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 15:27:56 by gmasid            #+#    #+#             */
/*   Updated: 2022/12/08 16:03:53 by gmasid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/minishell.h"

int	can_execute_in_child_process(t_cmd *cmd)
{
	if (is_builtin(cmd))
		return (1);
	return (cmd->cmd_path && access(cmd->cmd_path, X_OK) == 0);
}

int	execute_command_in_child_process(t_list *node, t_data *data)
{
	t_cmd	*cmd;

	cmd = node->content;
	set_child_process_signal_handlers();
	if (is_builtin(cmd))
		return (handle_generate_output_builtin(node, data));
	execve(cmd->cmd_path, cmd->full_cmd, data->envp);
	return (1);
}

int	handle_redirections(t_list *node, int fd[2])
{
	t_cmd	*cmd;

	cmd = node->content;
	if (cmd->infile != STDIN_FILENO)
	{
		if (dup2(cmd->infile, STDIN_FILENO) == -1)
			return (throw_error(DUPERR, 1, NULL));
		close(cmd->infile);
	}
	if (cmd->outfile != STDOUT_FILENO)
	{
		if (dup2(cmd->outfile, STDOUT_FILENO) == -1)
			return (throw_error(DUPERR, 1, NULL));
		close(cmd->outfile);
	}
	if (node->next && cmd->outfile == STDOUT_FILENO)
	{
		if (dup2(fd[WRITE_END], STDOUT_FILENO) == -1)
			return (throw_error(DUPERR, 1, NULL));
		close(fd[WRITE_END]);
	}
	return (1);
}

void	handle_child_process(t_list *node, t_data *data, int fd[2])
{
	handle_redirections(node, fd);
	close(fd[READ_END]);
	execute_command_in_child_process(node, data);
	ft_lstclear(&data->cmds, free_node);
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

int	execute(t_list *node, t_data *data, int fd[2])
{
	t_cmd	*cmd;

	cmd = node->content;
	if (cmd->infile == -1 || cmd->outfile == -1)
		return (1);
	if (can_execute_in_child_process(cmd))
		handle_execution(node, data, fd);
	return (1);
}
