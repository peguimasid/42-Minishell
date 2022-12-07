/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 12:52:30 by gmasid            #+#    #+#             */
/*   Updated: 2022/12/07 12:54:01 by gmasid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

int	clean_up(DIR *current_folder_dir, char **path_splited)
{
	if (current_folder_dir)
		closedir(current_folder_dir);
	free_matrix(path_splited);
	return (1);
}

char	*find_command(char **env_path, char *cmd, char *cmd_path)
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
