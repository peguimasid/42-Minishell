/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 14:49:42 by gmasid            #+#    #+#             */
/*   Updated: 2022/11/30 17:29:13 by gmasid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	fill_nodes(t_data *data)
{
	char	**trimmed_args;

	trimmed_args = trim_args(data->args);
	print_matrix(trimmed_args);
	free_matrix(trimmed_args);
}

void	parse_args(t_data *data)
{
	fill_nodes(data);
}
