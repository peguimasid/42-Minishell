/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 11:15:30 by gmasid            #+#    #+#             */
/*   Updated: 2022/12/09 11:48:06 by gmasid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

int	has_next_arg(t_cmd *cmd, int i)
{
	return (cmd && cmd->full_cmd && cmd->full_cmd[i + 1]);
}

int	send_newline_flag(t_cmd *cmd)
{
	int	send_param;
	int	match_len;

	if (!cmd || !cmd->full_cmd || !cmd->full_cmd[0] || !cmd->full_cmd[1])
		return (0);
	match_len = ft_strlen(cmd->full_cmd[1]) == 2;
	send_param = (ft_strncmp(cmd->full_cmd[1], "-n", 2) == 0 && match_len);
	return (send_param);
}

int	execute_echo(t_cmd *cmd)
{
	int	i;

	i = 1;
	if (send_newline_flag(cmd))
		i++;
	while (cmd && cmd->full_cmd[i])
	{
		printf("%s", cmd->full_cmd[i]);
		if (has_next_arg(cmd, i))
			printf(" ");
		i++;
	}
	if (!send_newline_flag(cmd))
		printf("\n");
	return (1);
}

int	is_echo(t_cmd *node)
{
	char	*cmd;

	cmd = node->full_cmd[0];
	if (!cmd)
		return (0);
	if (ft_strncmp(cmd, "echo", ft_strlen(cmd)) == 0 && ft_strlen(cmd) == 4)
		return (1);
	return (0);
}
