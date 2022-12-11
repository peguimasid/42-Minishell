/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 17:43:43 by gmasid            #+#    #+#             */
/*   Updated: 2022/12/09 11:29:06 by gmasid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

int	execute_env(t_data *data)
{
	print_matrix(data->envp);
	return (1);
}

int	is_env(t_cmd *node)
{
	char	*cmd;

	cmd = node->full_cmd[0];
	if (!cmd)
		return (0);
	if (ft_strncmp(cmd, "env", ft_strlen(cmd)) == 0 && ft_strlen(cmd) == 3)
		return (1);
	return (0);
}
