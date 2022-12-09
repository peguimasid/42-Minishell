/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 19:47:54 by gmasid            #+#    #+#             */
/*   Updated: 2022/12/09 19:49:26 by gmasid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

int	execute_unset(t_cmd *cmd, t_data *data)
{
	(void)cmd;
	(void)data;
	printf("Unset");
	return (1);
}

int	is_unset(t_cmd *node)
{
	char *cmd;

	cmd = node->full_cmd[0];
	if (!cmd)
		return (0);
	if (ft_strncmp(cmd, "unset", ft_strlen(cmd)) == 0 && ft_strlen(cmd) == 5)
		return (1);
	return (0);
}