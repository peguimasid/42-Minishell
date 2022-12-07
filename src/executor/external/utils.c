/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 12:52:30 by gmasid            #+#    #+#             */
/*   Updated: 2022/12/07 14:02:38 by gmasid           ###   ########.fr       */
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

int	send_absolute_path_to_command(t_cmd *cmd)
{
	return (cmd && cmd->full_cmd && ft_strchr(*cmd->full_cmd, '/'));
}

int	send_relative_path_to_command(t_cmd *cmd)
{
	return (!is_builtin(cmd) && cmd && cmd->full_cmd);
}
