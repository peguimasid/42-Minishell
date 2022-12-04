/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_commands.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 11:33:27 by gmasid            #+#    #+#             */
/*   Updated: 2022/12/04 12:25:01 by gmasid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

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
	return (1);
}
