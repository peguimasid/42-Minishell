/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 19:47:54 by gmasid            #+#    #+#             */
/*   Updated: 2022/12/09 19:59:39 by gmasid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

int	execute_unset(t_cmd *cmd, t_data *data)
{
	char	*env_to_remove;
	int		index_to_remove;

	if (!cmd || !cmd->full_cmd[1])
		return (1);
	env_to_remove = cmd->full_cmd[1];
	index_to_remove = get_env_index(env_to_remove, data->envp);
	if (index_to_remove < 0)
		return (1);
	data->envp = matrix_remove(data->envp, index_to_remove);
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