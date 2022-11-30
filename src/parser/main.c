/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 14:49:42 by gmasid            #+#    #+#             */
/*   Updated: 2022/11/30 14:24:38 by gmasid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	fill_nodes(t_data *data)
{
	// t_list *aux;
	// char   **trimmed_args;
	// int i;
	//
	// trimmed_args = trim_args(data->args);
	// i = -1;
	// while(args[i++]) {
	// 	aux = ft_lstlast(data->cmds);
	// 		if(should_create_node(data, i))
	// 			create_new_node(data, aux);
	//  aux->content = get_params(aux->content, data->args, trimmed_args, &i);
	//	if(i < 0) return (stop_fill(data->cmds, data, trimmed_args));
	// }
	// free_matrix(trimmed_args);
}

void	parse_args(t_data *data)
{
	fill_nodes(data);
}
