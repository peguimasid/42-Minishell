/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_commands.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 11:33:27 by gmasid            #+#    #+#             */
/*   Updated: 2022/12/04 12:51:04 by gmasid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

// TODO: Create function to return if command is builtin or other cmd type
// TODO: Create function to handle builtins and function to handle others

int	execute_commands(t_data *data)
{
	t_list	*current_node;
	t_cmd	*current_command;

	current_node = data->cmds;
	while (current_node)
	{
		current_command = current_node->content;
		printf("command => %s\n", *current_command->full_cmd);
		current_node = current_node->next;
	}
	wait_child_processes_exit(data);
	return (1);
}
