/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucafern <lucafern@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 09:19:52 by gmasid            #+#    #+#             */
/*   Updated: 2022/12/04 15:21:22 by lucafern         ###   ########.fr       */
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

void	define_cmd_path(t_cmd *cmd, t_data *data)
{
	if (str_ichr(cmd->full_cmd[0], '/') > -1)
		cmd->cmd_path = cmd->full_cmd[0];
	else
		cmd->cmd_path = find_cmd_path(data, cmd->full_cmd[0]);
}
