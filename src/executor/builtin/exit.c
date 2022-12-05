/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 18:28:22 by gmasid            #+#    #+#             */
/*   Updated: 2022/12/05 18:35:10 by gmasid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

int	execute_exit(t_cmd *cmd)
{
	(void)cmd;
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
