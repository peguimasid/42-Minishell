/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_commands.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 11:33:27 by gmasid            #+#    #+#             */
/*   Updated: 2022/12/04 13:13:21 by gmasid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	handle_builtin(t_cmd *cmd)
{
	printf("BUILTIN\n");
	printf("command => %s\n\n", *cmd->full_cmd);
	return (1);
}

int	handle_command(t_cmd *cmd)
{
	printf("OTHER\n");
	printf("command => %s\n\n", *cmd->full_cmd);
	return (1);
}

int	execute_commands(t_data *data)
{
	t_list	*current_node;
	t_cmd	*current_command;
	int		command_type;
	int		status;

	current_node = data->cmds;
	status = 1;
	while (current_node)
	{
		current_command = current_node->content;
		command_type = get_command_type(current_command);
		if (command_type == BUILTIN)
			status = handle_builtin(current_command);
		if (command_type == OTHER)
			status = handle_command(current_command);
		current_node = current_node->next;
	}
	wait_child_processes_exit(data);
	return (status);
}
