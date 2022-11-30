/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 14:49:42 by gmasid            #+#    #+#             */
/*   Updated: 2022/11/30 17:54:43 by gmasid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	should_create_node(t_data *data, int i)
{
	int	is_pipe;
	int	has_args_after_pipe;

	is_pipe = data->args[i][0] == '|';
	has_args_after_pipe = data->args[i + 1] && data->args[i + 1][0];
	if (i == 0)
		return (1);
	if (is_pipe && has_args_after_pipe)
		return (1);
	return (0);
}

void	fill_nodes(t_data *data)
{
	char	**trimmed_args;
	t_list	*aux;
	int		i;

	trimmed_args = trim_args(data->args);
	i = 0;
	while (data->args[i])
	{
		aux = ft_lstlast(data->cmds);
		if (should_create_node(data, i))
		{
			i += data->args[i][0] == '|';
			ft_lstadd_back(&data->cmds, ft_lstnew(new_node()));
			aux = ft_lstlast(data->cmds);
			printf("create node\n");
		}
		(void)aux;
		i++;
	}
	free_matrix(trimmed_args);
}

void	parse_args(t_data *data)
{
	fill_nodes(data);
}
