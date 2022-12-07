/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_cmd_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 14:21:10 by gmasid            #+#    #+#             */
/*   Updated: 2022/12/07 17:09:33 by gmasid           ###   ########.fr       */
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

int	is_current_folder_dir(t_cmd *cmd)
{
	DIR	*dir;

	dir = NULL;
	if (!cmd || !cmd->full_cmd)
		return (0);
	dir = opendir(cmd->full_cmd[0]);
	if (!dir)
		return (0);
	closedir(dir);
	return (1);
}

int	set_path(t_data *data, t_list *node)
{
	t_cmd	*cmd;

	cmd = node->content;
	if (is_current_folder_dir(cmd))
		return (1);
	if (send_absolute_path_to_command(cmd))
	{
		cmd->cmd_path = set_absolute_path(cmd);
		return (0);
	}
	if (send_relative_path_to_command(cmd))
	{
		cmd->cmd_path = find_command_path(*cmd->full_cmd, data);
		return (0);
	}
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
