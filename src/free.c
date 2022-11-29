/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 17:31:19 by gmasid            #+#    #+#             */
/*   Updated: 2022/11/29 15:10:20 by gmasid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	free_data(t_data *data)
{
	free_matrix(data->envp);
}

void	free_node(void *node)
{
	t_cmd	*cmd;

	cmd = node;
	free_matrix(cmd->full_cmd);
	free(cmd->cmd_path);
	if (cmd->infile != STDIN_FILENO)
		close(cmd->infile);
	if (cmd->outfile != STDOUT_FILENO)
		close(cmd->outfile);
	free(cmd);
}

void	clean(t_data *data)
{
	free_matrix(data->args);
	free(data->input);
	if (data && data->cmds)
		ft_lstclear(&data->cmds, free_node);
}
