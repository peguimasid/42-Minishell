/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file_descriptors.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 11:25:45 by gmasid            #+#    #+#             */
/*   Updated: 2022/12/01 16:57:18 by gmasid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	open_file(char *path, t_cmd *node, int is_write, int is_append)
{
	if (node->outfile > 2)
		close(node->outfile);
	if (!path)
		return (-1);
	if (access(path, F_OK) == -1 && !is_write)
		throw_error(NDIR, 127, path);
	else if (!is_write && access(path, R_OK) == -1)
		throw_error(NPERM, 126, path);
	else if (is_write && access(path, W_OK) == -1 && access(path, F_OK) == 0)
		throw_error(NPERM, 126, path);
	if (is_write && is_append)
		node->outfile = open(path, O_CREAT | O_WRONLY | O_APPEND, 0666);
	else if (is_write && !is_append)
		node->outfile = open(path, O_CREAT | O_WRONLY | O_TRUNC, 0666);
	else if (!is_write && node->outfile != -1)
		node->outfile = open(path, O_RDONLY);
	else
		node->outfile = node->outfile;
	return (node->outfile);
}

int	set_infile_fd(t_cmd *node, char **trimmed_args, int i)
{
	int	status;
	int	file_position;

	file_position = i + 1;
	if (trimmed_args[file_position])
		status = open_file(trimmed_args[file_position], node, 0, 0);
	if (!trimmed_args[file_position])
	{
		throw_error(OPENFILEERR, 2, NULL);
		return (-1);
	}
	if (status == -1)
	{
		g_status = 1;
		return (-1);
	}
	return (2);
}

int	set_outfile_fd(t_cmd *node, char **trimmed_args, int i)
{
	int	status;
	int	file_position;

	file_position = i + 1;
	if (trimmed_args[file_position])
		status = open_file(trimmed_args[file_position], node, 1, 0);
	if (!trimmed_args[file_position])
	{
		throw_error(OPENFILEERR, 2, NULL);
		return (-1);
	}
	if (status == -1)
	{
		g_status = 1;
		return (-1);
	}
	return (2);
}

int	set_append_outfile_fd(t_cmd *node, char **trimmed_args, int i)
{
	int	status;
	int	file_position;

	file_position = i + 2;
	if (trimmed_args[file_position])
		status = open_file(trimmed_args[file_position], node, 1, 1);
	if (!trimmed_args[file_position])
	{
		throw_error(OPENFILEERR, 2, NULL);
		return (-1);
	}
	if (status == -1)
	{
		g_status = 1;
		return (-1);
	}
	return (3);
}
