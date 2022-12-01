/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_nodes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 17:56:26 by gmasid            #+#    #+#             */
/*   Updated: 2022/12/01 10:53:17 by gmasid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	should_create_node(t_data *data, int i)
{
	int	is_pipe;
	int	has_args_after_pipe;

	is_pipe = data->args[i][0] == '|';
	has_args_after_pipe = (data->args[i + 1] && data->args[i + 1][0]);
	if (i == 0)
		return (1);
	if (is_pipe && has_args_after_pipe)
		return (1);
	return (0);
}

void	quit_parsing(t_data *data, char **trimmed_args)
{
	ft_lstclear(&data->cmds, free_node);
	free_matrix(trimmed_args);
}

int	empty_pipe_error(void)
{
	throw_error(PIPENDERR, 2, NULL);
	return (-1);
}

int	fill_current_node(t_cmd *node, char **trimmed_args, t_data *data, int i)
{
	int	argument_type;

	argument_type = get_argument_type(data->args, i);
	if (argument_type == PIPE || argument_type == NO_ARG)
		return (empty_pipe_error());
	if (argument_type == APPEND_OUTPUT)
		return (3);
	if (argument_type == HEREDOC)
		return (3);
	if (argument_type == REDIRECT_OUTPUT)
		return (2);
	if (argument_type == REDIRECT_INPUT)
		return (2);
	if (argument_type == NORMAL_ARG)
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
	offset = 0;
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
		if (offset < 0)
			return (quit_parsing(data, trimmed_args));
		i += offset;
	}
	free_matrix(trimmed_args);
}
