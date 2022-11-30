/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 14:49:42 by gmasid            #+#    #+#             */
/*   Updated: 2022/11/30 18:14:05 by gmasid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	print_nodes(t_data *data)
{
	int		i;
	t_cmd	*curr;

	i = 1;
	while (data->cmds)
	{
		curr = data->cmds->content;
		printf("------- Node %d -------\n", i);
		printf("full_cmd:\n");
		print_matrix(curr->full_cmd);
		printf("infile => %d\n", curr->infile);
		printf("outfile => %d\n", curr->outfile);
		printf("-----------------------\n\n");
		data->cmds = data->cmds->next;
		i++;
	}
}

void	parse_args(t_data *data)
{
	fill_nodes(data);
	print_nodes(data);
}
