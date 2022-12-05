/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 18:28:22 by gmasid            #+#    #+#             */
/*   Updated: 2022/12/05 19:11:45 by gmasid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

int	execute_exit(t_cmd *cmd)
{
	ft_putendl_fd("exit", 2);
	if (!cmd->full_cmd || !cmd->full_cmd[1])
	{
		g_status = 0;
		return (0);
	}
	if (cmd->full_cmd[2])
	{
		ft_putendl_fd("minishell: exit: too many arguments", 2);
		return (1);
	}
	g_status = restrict_atoi(cmd->full_cmd[1]);
	if (g_status == -1)
	{
		ft_putstr_fd("minishell: exit: ", 2);
		ft_putstr_fd(cmd->full_cmd[1], 2);
		ft_putstr_fd(": numeric argument required\n", 2);
		g_status = 255;
	}
	g_status %= 256;
	return (0);
}

int	is_exit(t_cmd *node)
{
	char	*cmd;

	cmd = node->full_cmd[0];
	if (!cmd)
		return (0);
	if (ft_strncmp(cmd, "exit", ft_strlen(cmd)) == 0 && ft_strlen(cmd) == 4)
		return (1);
	return (0);
}
