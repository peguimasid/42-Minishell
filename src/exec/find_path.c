/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 09:19:52 by gmasid            #+#    #+#             */
/*   Updated: 2022/10/29 09:21:24 by gmasid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	free_pointer_and_contents(char **ptr)
{
	int	i;

	i = 0;
	while (ptr[i])
		free(ptr[i++]);
	free(ptr);
}

char	*find_cmd_path(char *cmd, char **envp)
{
	char	**paths;
	char	*part_path;
	char	*cmd_path;
	int		i;

	// TODO: Change this function get value from "t_env" struct
	paths = ft_split(get_env(envp, "PATH"), ':');
	i = 0;
	while (paths[i])
	{
		part_path = ft_strjoin(paths[i], "/");
		cmd_path = ft_strjoin(part_path, cmd);
		free(part_path);
		if (access(cmd_path, F_OK) == 0)
		{
			free_pointer_and_contents(paths);
			return (cmd_path);
		}
		i++;
	}
	free_pointer_and_contents(paths);
	return (cmd);
}
