/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 18:18:27 by gmasid            #+#    #+#             */
/*   Updated: 2022/12/06 12:49:49 by gmasid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

int	handle_config_builtin(t_list *node, t_data *data)
{
	t_cmd	*command;

	command = node->content;
	(void)data;
	if (is_exit(command))
		return (execute_exit(command));
	printf("Change config\n");
	printf("command => %s\n\n", *command->full_cmd);
	return (1);
}