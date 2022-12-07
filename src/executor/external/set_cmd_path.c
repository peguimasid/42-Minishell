/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_cmd_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 14:21:10 by gmasid            #+#    #+#             */
/*   Updated: 2022/12/07 17:19:27 by gmasid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	handle_set_absolute_path(t_cmd *cmd)
{
	cmd->cmd_path = set_absolute_path(cmd);
}

void	handle_set_relative_path(t_cmd *cmd, t_data *data)
{
	cmd->cmd_path = find_command_path(*cmd->full_cmd, data);
}

void	set_path(t_data *data, t_list *node)
{
	t_cmd	*cmd;

	cmd = node->content;
	if (is_current_folder_dir(cmd))
		return ;
	if (send_absolute_path_to_command(cmd))
		return (handle_set_absolute_path(cmd));
	if (send_relative_path_to_command(cmd))
		return (handle_set_relative_path(cmd, data));
}

void	handle_cmd_path(t_data *data, t_list *node)
{
	t_cmd	*cmd;

	cmd = node->content;
	set_path(data, node);
	check_for_errors(cmd);
}
