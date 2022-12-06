/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 16:24:43 by gmasid            #+#    #+#             */
/*   Updated: 2022/12/06 16:24:45 by gmasid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

int	is_builtin(t_cmd *node)
{
	char	*cmd;

	cmd = node->full_cmd[0];
	if (!cmd)
		return (0);
	if (ft_strchr(cmd, '/'))
		return (0);
	if (node->cmd_path && ft_strchr(node->cmd_path, '/'))
		return (0);
	if (ft_strncmp(cmd, "pwd", ft_strlen(cmd)) == 0 && ft_strlen(cmd) == 3)
		return (1);
	if (ft_strncmp(cmd, "env", ft_strlen(cmd)) == 0 && ft_strlen(cmd) == 3)
		return (1);
	if (ft_strncmp(cmd, "cd", ft_strlen(cmd)) == 0 && ft_strlen(cmd) == 2)
		return (1);
	if (ft_strncmp(cmd, "export", ft_strlen(cmd)) == 0 && ft_strlen(cmd) == 6)
		return (1);
	if (ft_strncmp(cmd, "unset", ft_strlen(cmd)) == 0 && ft_strlen(cmd) == 5)
		return (1);
	if (ft_strncmp(cmd, "echo", ft_strlen(cmd)) == 0 && ft_strlen(cmd) == 4)
		return (1);
	if (ft_strncmp(cmd, "exit", ft_strlen(cmd)) == 0 && ft_strlen(cmd) == 4)
		return (1);
	return (0);
}

int	is_config_builtin(t_cmd *node)
{
	char *cmd;

	cmd = node->full_cmd[0];
	if (!cmd)
		return (0);
	if (ft_strchr(cmd, '/'))
		return (0);
	if (node->cmd_path && ft_strchr(node->cmd_path, '/'))
		return (0);
	if (ft_strncmp(cmd, "cd", ft_strlen(cmd)) == 0 && ft_strlen(cmd) == 2)
		return (1);
	if (ft_strncmp(cmd, "export", ft_strlen(cmd)) == 0 && ft_strlen(cmd) == 6)
		return (1);
	if (ft_strncmp(cmd, "unset", ft_strlen(cmd)) == 0 && ft_strlen(cmd) == 5)
		return (1);
	if (ft_strncmp(cmd, "exit", ft_strlen(cmd)) == 0 && ft_strlen(cmd) == 4)
		return (1);
	return (0);
}