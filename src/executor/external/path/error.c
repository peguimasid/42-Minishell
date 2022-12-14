/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 17:16:28 by gmasid            #+#    #+#             */
/*   Updated: 2022/12/07 17:29:20 by gmasid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/minishell.h"

int	is_folder_in_current_directory(t_cmd *cmd)
{
	if (is_builtin(cmd))
		return (0);
	return (is_current_folder_dir(cmd));
}

int	no_such_file_or_dir(t_cmd *cmd)
{
	if (is_builtin(cmd))
		return (0);
	return (cmd && cmd->cmd_path && access(cmd->cmd_path, F_OK) == -1);
}

int	permission_denied(t_cmd *cmd)
{
	if (is_builtin(cmd))
		return (0);
	return (cmd && cmd->cmd_path && access(cmd->cmd_path, X_OK) == -1);
}

int	command_not_found(t_cmd *cmd)
{
	if (is_builtin(cmd))
		return (0);
	return (!cmd->cmd_path || !cmd->full_cmd[0] || !cmd->full_cmd[0][0]);
}

int	check_for_errors(t_cmd *cmd)
{
	if (is_folder_in_current_directory(cmd))
		return (throw_error(IS_DIR, 126, *cmd->full_cmd));
	if (no_such_file_or_dir(cmd))
		return (throw_error(NDIR, 127, cmd->cmd_path));
	if (permission_denied(cmd))
		return (throw_error(NPERM, 126, cmd->cmd_path));
	if (command_not_found(cmd))
		return (throw_error(NOTFOUNDCMD, 127, *cmd->full_cmd));
	return (0);
}
