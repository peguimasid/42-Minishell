/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 14:49:42 by gmasid            #+#    #+#             */
/*   Updated: 2022/12/01 13:01:04 by gmasid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	print_nodes(t_data *data)
{
	int		i;
	t_cmd	*curr;
	t_list	*curr_node;

	i = 1;
	curr_node = data->cmds;
	while (curr_node)
	{
		curr = curr_node->content;
		printf("------- Node %d -------\n", i);
		printf("full_cmd:\n");
		print_matrix(curr->full_cmd);
		printf("infile => %d\n", curr->infile);
		printf("outfile => %d\n", curr->outfile);
		printf("-----------------------\n\n");
		curr_node = curr_node->next;
		i++;
	}
}

void	parse_args(t_data *data)
{
	fill_nodes(data);
	print_nodes(data);
}
