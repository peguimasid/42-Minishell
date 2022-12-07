/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 12:52:30 by gmasid            #+#    #+#             */
/*   Updated: 2022/12/07 14:12:10 by gmasid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

char	*find_command_path(char *cmd, t_data *data)
{
	char	*temp;
	char	*result;
	char	**env_splited;
	int		i;

	temp = get_env("PATH", data->envp, 4);
	env_splited = ft_split(temp, ':');
	free(temp);
	i = -1;
	result = NULL;
	while (env_splited && env_splited[++i])
	{
		free(result);
		temp = ft_strjoin(env_splited[i], "/");
		result = ft_strjoin(temp, cmd);
		free(temp);
		if (access(result, F_OK) == 0)
		{
			free_matrix(env_splited);
			return (result);
		}
	}
	free(result);
	free_matrix(env_splited);
	return (NULL);
}

char	*set_absolute_path(t_cmd *cmd)
{
	char	*result;
	char	**s;

	s = ft_split(*cmd->full_cmd, '/');
	result = ft_strdup(*cmd->full_cmd);
	free(cmd->full_cmd[0]);
	cmd->full_cmd[0] = ft_strdup(s[matrix_len(s) - 1]);
	free_matrix(s);
	return (result);
}

int	send_absolute_path_to_command(t_cmd *cmd)
{
	return (cmd && cmd->full_cmd && ft_strchr(*cmd->full_cmd, '/'));
}

int	send_relative_path_to_command(t_cmd *cmd)
{
	return (!is_builtin(cmd) && cmd && cmd->full_cmd);
}
