/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_commands.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 11:33:27 by gmasid            #+#    #+#             */
/*   Updated: 2022/12/05 18:22:26 by gmasid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	handle_command(t_cmd *command, int has_next)
{
	if (!command->full_cmd)
		return (1);
	if (is_config_builtin(command) && !has_next)
		return (handle_config_builtin(command));
	return (handle_generate_output(command));
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
		status = handle_command(command, has_next(current_node));
		current_node = current_node->next;
	}
	wait_child_processes_exit(data);
	return (status);
}
