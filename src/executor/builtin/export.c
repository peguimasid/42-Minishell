/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 21:48:12 by gmasid            #+#    #+#             */
/*   Updated: 2022/12/09 21:49:23 by gmasid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

int	execute_export(t_cmd *cmd, t_data *data)
{
	(void)cmd;
	(void)data;
	printf("export\n");
	return (1);
}

int	is_export(t_cmd *node)
{
	char	*cmd;

	cmd = node->full_cmd[0];
	if (!cmd)
		return (0);
	if (ft_strncmp(cmd, "export", ft_strlen(cmd)) == 0 && ft_strlen(cmd) == 6)
		return (1);
	return (0);
}
