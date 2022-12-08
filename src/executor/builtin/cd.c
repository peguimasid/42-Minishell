/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 16:50:58 by gmasid            #+#    #+#             */
/*   Updated: 2022/12/08 17:30:37 by gmasid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

int	execute_cd(t_cmd *cmd, t_data *data)
{
	char	*path;
	char	cwd[PATH_MAX];

	getcwd(cwd, sizeof(cwd));
	if (!cmd->full_cmd[1])
	{
		path = get_env("HOME", data->envp, 4);
		if (chdir(path) != 0)
			perror("Error");
		free(path);
		return (1);
	}
	if (cmd->full_cmd[2])
	{
		printf("cd: string not in pwd: %s\n", cmd->full_cmd[1]);
		return (1);
	}
	if (chdir(cmd->full_cmd[1]) != 0)
		printf("%s: %s\n", strerror(errno), cmd->full_cmd[1]);
	return (1);
}

int	is_cd(t_cmd *node)
{
	char	*cmd;

	cmd = node->full_cmd[0];
	if (!cmd)
		return (0);
	if (ft_strncmp(cmd, "cd", ft_strlen(cmd)) == 0 && ft_strlen(cmd) == 2)
		return (1);
	return (0);
}
