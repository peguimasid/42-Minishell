/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 18:18:27 by gmasid            #+#    #+#             */
/*   Updated: 2022/12/08 16:54:42 by gmasid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

// TODO: cd, export, unset
int	handle_config_builtin(t_list *node, t_data *data)
{
	t_cmd	*command;

	command = node->content;
	if (is_exit(command))
		return (execute_exit(command));
	if (is_cd(command))
		return (execute_cd(command, data));
	return (1);
}

// TODO: echo, pwd, env
int	handle_generate_output_builtin(t_list *node, t_data *data)
{
	t_cmd	*command;

	command = node->content;
	(void)data;
	printf("Generate output\n");
	printf("command => %s\n\n", *command->full_cmd);
	return (1);
}
