/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucafern <lucafern@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 09:19:52 by gmasid            #+#    #+#             */
/*   Updated: 2022/12/01 14:05:21 by lucafern         ###   ########.fr       */
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

char	*find_cmd_path(t_data *data, char *cmd)
{
	char	**paths;
	char	*part_path;
	char	*cmd_path;
	int		i;

	paths = ft_split(get_env("PATH", data->envp, 4), ':');
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
		free(cmd_path);
		i++;
	}
	free_pointer_and_contents(paths);
	return (cmd);
}
