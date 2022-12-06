/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_commands.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 11:33:27 by gmasid            #+#    #+#             */
/*   Updated: 2022/12/06 12:45:30 by gmasid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	handle_command(t_list *node, t_data *data)
{
	t_cmd	*command;

	command = node->content;
	if (!command->full_cmd)
		return (1);
	if (is_config_builtin(command) && !has_next(node))
		return (handle_config_builtin(command, data));
	return (handle_generate_output(command, data));
}

int	execute_commands(t_data *data)
{
	t_list	*current_node;
	int		status;

	current_node = data->cmds;
	status = 1;
	while (current_node)
	{
		status = handle_command(current_node, data);
		current_node = current_node->next;
	}
	wait_child_processes_exit(data);
	return (status);
}
