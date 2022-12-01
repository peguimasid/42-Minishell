/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file_descriptors.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 11:25:45 by gmasid            #+#    #+#             */
/*   Updated: 2022/12/01 17:17:32 by gmasid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	open_file(char *path, int oldfd, int is_write, int is_append)
{
	int	fd;

	if (oldfd > 2)
		close(oldfd);
	if (!path)
		return (-1);
	if (access(path, F_OK) == -1 && !is_write)
		throw_error(NDIR, 127, path);
	else if (!is_write && access(path, R_OK) == -1)
		throw_error(NPERM, 126, path);
	else if (is_write && access(path, W_OK) == -1 && access(path, F_OK) == 0)
		throw_error(NPERM, 126, path);
	if (is_write && is_append)
		fd = open(path, O_CREAT | O_WRONLY | O_APPEND, 0666);
	else if (is_write && !is_append)
		fd = open(path, O_CREAT | O_WRONLY | O_TRUNC, 0666);
	else if (!is_write && oldfd != -1)
		fd = open(path, O_RDONLY);
	else
		fd = oldfd;
	return (fd);
}

int	set_infile_fd(t_cmd *node, char **args, int i)
{
	int	file_position;

	file_position = i + 1;
	if (args[file_position])
		node->infile = open_file(args[file_position], node->infile, 0, 0);
	if (!args[file_position])
	{
		throw_error(OPENFILEERR, 2, NULL);
		return (-1);
	}
	if (node->infile == -1)
	{
		g_status = 1;
		return (-1);
	}
	return (2);
}

int	set_outfile_fd(t_cmd *node, char **args, int i)
{
	int	file_position;

	file_position = i + 1;
	if (args[file_position])
		node->outfile = open_file(args[file_position], node->outfile, 1, 0);
	if (!args[file_position])
	{
		throw_error(OPENFILEERR, 2, NULL);
		return (-1);
	}
	if (node->outfile == -1)
	{
		g_status = 1;
		return (-1);
	}
	return (2);
}

int	set_append_outfile_fd(t_cmd *node, char **args, int i)
{
	int	file_position;

	file_position = i + 2;
	if (args[file_position])
		node->outfile = open_file(args[file_position], node->outfile, 1, 1);
	if (!args[file_position])
	{
		throw_error(OPENFILEERR, 2, NULL);
		return (-1);
	}
	if (node->outfile == -1)
	{
		g_status = 1;
		return (-1);
	}
	return (3);
}
