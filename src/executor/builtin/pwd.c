/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 20:11:37 by gmasid            #+#    #+#             */
/*   Updated: 2022/12/09 20:13:54 by gmasid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

int	execute_pwd(void)
{
	char	*cwd;

	cwd = getcwd(NULL, 0);
	printf("%s\n", cwd);
	free(cwd);
	return (1);
}

int	is_pwd(t_cmd *node)
{
	char *cmd;

	cmd = node->full_cmd[0];
	if (!cmd)
		return (0);
	if (ft_strncmp(cmd, "pwd", ft_strlen(cmd)) == 0 && ft_strlen(cmd) == 3)
		return (1);
	return (0);
}