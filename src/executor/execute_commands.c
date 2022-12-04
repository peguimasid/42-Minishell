/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_commands.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 11:33:27 by gmasid            #+#    #+#             */
/*   Updated: 2022/12/04 18:28:05 by gmasid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	handle_config_builtin(t_cmd *cmd)
{
	printf("Change config\n");
	printf("command => %s\n\n", *cmd->full_cmd);
	return (1);
}

int	handle_others(t_cmd *cmd)
{
	printf("Generate output\n");
	printf("command => %s\n\n", *cmd->full_cmd);
	return (1);
}

int	handle_command(t_cmd *command)
{
	if (is_config_builtin(command))
		return (handle_config_builtin(command));
	return (handle_others(command));
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
