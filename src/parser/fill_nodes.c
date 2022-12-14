/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_nodes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 17:56:26 by gmasid            #+#    #+#             */
/*   Updated: 2022/12/10 22:38:45 by gmasid           ###   ########.fr       */
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

int	fill_current_node(t_cmd *node, char **trimmed_args, t_data *data, int i)
{
	int	argument_type;

	argument_type = get_argument_type(data->args, i);
	if (argument_type == PIPE || argument_type == NO_ARG)
		return (empty_pipe_error());
	if (argument_type == APPEND_OUTPUT)
		return (set_append_outfile_fd(node, trimmed_args, i));
	if (argument_type == HEREDOC)
		return (set_heredoc_fd(node, trimmed_args, i));
	if (argument_type == REDIRECT_OUTPUT)
		return (set_outfile_fd(node, trimmed_args, i));
	if (argument_type == REDIRECT_INPUT)
		return (set_infile_fd(node, trimmed_args, i));
	if (argument_type == NORMAL_ARG)
		node->full_cmd = matrix_push(node->full_cmd, trimmed_args[i]);
	return (1);
}

void	populate_command_nodes(t_data *data, char **trimmed_args)
{
	t_list	*curr_node;
	int		offset;
	int		i;

	i = 0;
	offset = 0;
	while (data->args && data->args[i])
	{
		if (should_create_node(data, i))
		{
			i += data->args[i][0] == '|';
			ft_lstadd_back(&data->cmds, ft_lstnew(new_node()));
		}
		curr_node = ft_lstlast(data->cmds);
		offset = fill_current_node(curr_node->content, trimmed_args, data, i);
		if (offset < 0)
			return (quit_parsing(data));
		i += offset;
	}
}

void	fill_nodes(t_data *data)
{
	char	**trimmed_args;

	trimmed_args = trim_args(data->args);
	populate_command_nodes(data, trimmed_args);
	free_matrix(trimmed_args);
}
