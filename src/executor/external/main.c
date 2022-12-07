/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 18:22:12 by gmasid            #+#    #+#             */
/*   Updated: 2022/12/07 14:21:08 by gmasid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

int	handle_generate_output(t_list *node, t_data *data)
{
	t_cmd	*command;
	t_cmd	*next_command;
	t_list	*next_node;
	int		fd[2];

	command = node->content;
	next_node = node->next;
	handle_cmd_path(data, node);
	if (pipe(fd) == -1)
		return (throw_error(PIPERR, 1, NULL));
	close(fd[WRITE_END]);
	if (next_node)
	{
		next_command = next_node->content;
		if (next_command->infile == STDIN_FILENO)
			next_command->infile = fd[READ_END];
	}
	else
		close(fd[READ_END]);
	if (command->infile > 2)
		close(command->infile);
	if (command->outfile > 2)
		close(command->outfile);
	return (1);
}
