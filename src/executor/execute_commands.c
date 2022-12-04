/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_commands.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 11:33:27 by gmasid            #+#    #+#             */
/*   Updated: 2022/12/04 16:32:43 by gmasid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	handle_builtin(t_cmd *cmd)
{
	printf("BUILTIN\n");
	printf("command => %s\n\n", *cmd->full_cmd);
	return (1);
}

int	handle_extern(t_cmd *cmd)
{
	printf("EXTERN\n");
	printf("command => %s\n\n", *cmd->full_cmd);
	return (1);
}

int	handle_command(t_cmd *command)
{
	if (is_builtin(command))
		return (handle_builtin(command));
	return (handle_extern(command));
}

int	execute_commands(t_data *data)
{
	t_list	*current_node;
	t_cmd	*command;
	int		status;

	current_node = data->cmds;
	status = 1;
	while (current_node)
	{
		command = current_node->content;
		status = handle_command(command);
		current_node = current_node->next;
	}
	wait_child_processes_exit(data);
	return (status);
}
