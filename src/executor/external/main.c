/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 18:22:12 by gmasid            #+#    #+#             */
/*   Updated: 2022/12/06 16:56:04 by gmasid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

static void	clean_up(DIR *current_folder_dir, char **path_splited)
{
	if (current_folder_dir)
		closedir(current_folder_dir);
	free_matrix(path_splited);
}

static char	*find_command(char **env_path, char *cmd, char *cmd_path)
{
	char	*temp;
	int		i;

	i = -1;
	cmd_path = NULL;
	while (env_path && env_path[++i])
	{
		free(cmd_path);
		temp = ft_strjoin(env_path[i], "/");
		if (!temp)
			return (NULL);
		cmd_path = ft_strjoin(temp, cmd);
		free(temp);
		if (!cmd_path)
			return (NULL);
		if (access(cmd_path, F_OK) == 0)
			break ;
	}
	if (!env_path || !env_path[i])
	{
		free(cmd_path);
		return (NULL);
	}
	return (cmd_path);
}

static DIR	*cmd_checks(t_data *data, t_list *cmd, char **s, char *path)
{
	t_cmd	*n;
	DIR		*current_folder_dir;

	current_folder_dir = NULL;
	n = cmd->content;
	if (n && n->full_cmd)
		current_folder_dir = opendir(*n->full_cmd);
	if (n && n->full_cmd && ft_strchr(*n->full_cmd, '/') && !current_folder_dir)
	{
		s = ft_split(*n->full_cmd, '/');
		n->cmd_path = ft_strdup(*n->full_cmd);
		free(n->full_cmd[0]);
		n->full_cmd[0] = ft_strdup(s[matrix_len(s) - 1]);
	}
	else if (!is_builtin(n) && n && n->full_cmd && !current_folder_dir)
	{
		path = get_env("PATH", data->envp, 4);
		s = ft_split(path, ':');
		free(path);
		n->cmd_path = find_command(s, *n->full_cmd, n->cmd_path);
	}
	return (current_folder_dir);
}

void	set_cmd_path(t_data *data, t_list *node, char **s, char *path)
{
	t_cmd	*cmd;
	DIR		*current_folder_dir;

	cmd = node->content;
	current_folder_dir = cmd_checks(data, node, s, path);
	if (is_builtin(cmd))
		clean_up(current_folder_dir, s);
	if (cmd && cmd->full_cmd && current_folder_dir)
		throw_error(IS_DIR, 126, *cmd->full_cmd);
	else if (cmd && cmd->cmd_path && access(cmd->cmd_path, F_OK) == -1)
		throw_error(NDIR, 127, cmd->cmd_path);
	else if (cmd && cmd->cmd_path && access(cmd->cmd_path, X_OK) == -1)
		throw_error(NPERM, 126, cmd->cmd_path);
	else if (!cmd->cmd_path || !cmd->full_cmd[0] || !cmd->full_cmd[0][0])
		throw_error(NOTFOUNDCMD, 127, *cmd->full_cmd);
	clean_up(current_folder_dir, s);
}

int	handle_generate_output(t_list *node, t_data *data)
{
	t_cmd	*command;
	t_cmd	*next_command;
	t_list	*next_node;
	int		fd[2];

	command = node->content;
	next_node = node->next;
	set_cmd_path(data, node, NULL, NULL);
	if (pipe(fd) == -1)
		return (throw_error(PIPERR, 1, NULL));
	close(fd[WRITE_END]);
	if (next_node)
	{
		next_command = next_node->content;
		if (next_command->infile == STDIN_FILENO)
			next_command->infile = fd[READ_END];
	}
	else
		close(fd[READ_END]);
	if (command->infile > 2)
		close(command->infile);
	if (command->outfile > 2)
		close(command->outfile);
	return (1);
}
