/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_nodes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 17:56:26 by gmasid            #+#    #+#             */
/*   Updated: 2022/11/30 18:49:03 by gmasid           ###   ########.fr       */
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

int	fill_current_node(t_cmd *node, char **trimmed_args, t_data *data, int i)
{
	int		curr_arg;
	char	*has_next_arg;
	int		next_arg;

	curr_arg = data->args[i][0];
	has_next_arg = data->args[i + 1];
	next_arg = data->args[i + 1][0];
	if (!data->args[i])
		return (0);
	if (curr_arg == '>' && has_next_arg && next_arg == '>')
		return (3);
	if (curr_arg == '<' && has_next_arg && next_arg == '<')
		return (3);
	if (curr_arg == '>')
		return (2);
	if (curr_arg == '<')
		return (2);
	if (curr_arg != '|')
		node->full_cmd = matrix_push(node->full_cmd, trimmed_args[i]);
	return (1);
}

void	fill_nodes(t_data *data)
{
	char	**trimmed_args;
	t_list	*curr_node;
	int		offset;
	int		i;

	trimmed_args = trim_args(data->args);
	i = 0;
	while (data->args[i])
	{
		curr_node = ft_lstlast(data->cmds);
		if (should_create_node(data, i))
		{
			i += data->args[i][0] == '|';
			ft_lstadd_back(&data->cmds, ft_lstnew(new_node()));
			curr_node = ft_lstlast(data->cmds);
		}
		offset = fill_current_node(curr_node->content, trimmed_args, data, i);
		i += offset;
	}
	free_matrix(trimmed_args);
}
