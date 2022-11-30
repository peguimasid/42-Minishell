/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 17:33:44 by gmasid            #+#    #+#             */
/*   Updated: 2022/11/30 19:50:08 by gmasid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_cmd	*new_node(void)
{
	t_cmd	*node;

	node = malloc(sizeof(t_cmd));
	if (!node)
		return (NULL);
	node->full_cmd = NULL;
	node->cmd_path = NULL;
	node->infile = STDIN_FILENO;
	node->outfile = STDOUT_FILENO;
	return (node);
}

int	get_redirection_type(char **args, int i)
{
	int	curr_arg;
	int	has_next_arg;
	int	next_arg;

	if (!args[i])
		return (NO_ARG);
	curr_arg = args[i][0];
	has_next_arg = args[i + 1] != NULL;
	if (has_next_arg)
		next_arg = args[i + 1][0];
	if (curr_arg == '>' && has_next_arg && next_arg == '>')
		return (APPEND_OUTPUT);
	if (curr_arg == '<' && has_next_arg && next_arg == '<')
		return (HEREDOC);
	if (curr_arg == '>')
		return (REDIRECT_OUTPUT);
	if (curr_arg == '<')
		return (REDIRECT_INPUT);
	return (curr_arg == '|');
}
