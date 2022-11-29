/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 14:49:42 by gmasid            #+#    #+#             */
/*   Updated: 2022/11/29 17:24:01 by gmasid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	fill_nodes(t_data *data)
{
	// t_list *result;
	// t_list *aux;
	// char   **trim_args;
	// int i;
	//
	// trim_args = trim_args(data->args);
	// i = -1;
	// while(args[i++]) {
	// 	aux = ft_lstlast(result);
	// 		if(should_create_node(data, i))
	// 			create_new_node(data, aux);
	//  aux->content = get_params(aux->content, data->args, trim_args, &i);
	//	if(i < 0) return (stop_fill(result, data, trim_args));
	// }
	// free_matrix(trim_args);
	// free_matrix(args);
	// return (result);
}

void	parse_args(t_data *data)
{
	fill_nodes(data);
}
