/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 18:22:12 by gmasid            #+#    #+#             */
/*   Updated: 2022/12/07 14:16:39 by gmasid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

int	check_for_errors(t_cmd *cmd, int is_current_folder_dir)
{
	int	is_current_dir_folder;
	int	no_such_dir;
	int	perm_denied;
	int	not_found;

	is_current_dir_folder = (cmd && cmd->full_cmd && is_current_folder_dir);
	no_such_dir = (cmd && cmd->cmd_path && access(cmd->cmd_path, F_OK) == -1);
	perm_denied = (cmd && cmd->cmd_path && access(cmd->cmd_path, X_OK) == -1);
	not_found = (!cmd->cmd_path || !cmd->full_cmd[0] || !cmd->full_cmd[0][0]);
	if (is_current_dir_folder && !is_builtin(cmd))
		return (throw_error(IS_DIR, 126, *cmd->full_cmd));
	if (no_such_dir && !is_builtin(cmd))
		return (throw_error(NDIR, 127, cmd->cmd_path));
	if (perm_denied && !is_builtin(cmd))
		return (throw_error(NPERM, 126, cmd->cmd_path));
	if (not_found && !is_builtin(cmd))
		return (throw_error(NOTFOUNDCMD, 127, *cmd->full_cmd));
	return (0);
}

int	set_path(t_data *data, t_list *node)
{
	t_cmd	*cmd;
	DIR		*is_current_folder_dir;

	is_current_folder_dir = NULL;
	cmd = node->content;
	if (cmd && cmd->full_cmd)
		is_current_folder_dir = opendir(*cmd->full_cmd);
	if (is_current_folder_dir)
	{
		closedir(is_current_folder_dir);
		return (1);
	}
	if (send_absolute_path_to_command(cmd))
		cmd->cmd_path = set_absolute_path(cmd);
	if (send_relative_path_to_command(cmd))
		cmd->cmd_path = find_command_path(*cmd->full_cmd, data);
	return (0);
}

void	handle_cmd_path(t_data *data, t_list *node)
{
	t_cmd	*cmd;
	int		is_current_folder_dir;

	cmd = node->content;
	is_current_folder_dir = set_path(data, node);
	check_for_errors(cmd, is_current_folder_dir);
}

int	handle_generate_output(t_list *node, t_data *data)
{
	t_cmd	*command;
	t_cmd	*next_command;
	t_list	*next_node;
	int		fd[2];

	command = node->content;
	next_node = node->next;
	handle_cmd_path(data, node);
	if (pipe(fd) == -1)
		return (throw_error(PIPERR, 1, NULL));
	close(fd[WRITE_END]);
	if (next_node)
	{
		next_command = next_node->content;
		if (next_command->infile == STDIN_FILENO)
			next_command->infile = fd[READ_END];
	}
	else
		close(fd[READ_END]);
	if (command->infile > 2)
		close(command->infile);
	if (command->outfile > 2)
		close(command->outfile);
	return (1);
}
