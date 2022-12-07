/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 18:22:12 by gmasid            #+#    #+#             */
/*   Updated: 2022/12/07 17:48:13 by gmasid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	handle_file_descriptors(int fd[2], t_list *node)
{
	t_cmd	*command;
	t_cmd	*next_command;
	t_list	*next_node;

	command = node->content;
	next_node = node->next;
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
}

int	handle_generate_output(t_list *node, t_data *data)
{
	int	fd[2];

	handle_cmd_path(data, node);
	if (pipe(fd) == -1)
		return (throw_error(PIPERR, 1, NULL));
	handle_file_descriptors(fd, node);
	return (1);
}
