/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 18:22:12 by gmasid            #+#    #+#             */
/*   Updated: 2022/12/06 12:49:14 by gmasid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

int	handle_generate_output(t_list *node, t_data *data)
{
	t_cmd	*command;

	command = node->content;
	(void)data;
	printf("Generate output\n");
	printf("command => %s\n\n", *command->full_cmd);
	return (1);
}
