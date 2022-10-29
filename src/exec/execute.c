/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 13:49:30 by gmasid            #+#    #+#             */
/*   Updated: 2022/10/29 09:24:12 by gmasid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	execute_bin(char **args, char **envp)
{
	char	*path;

	if (str_ichr(args[0], '/') > -1)
		path = args[0];
	else
		path = find_cmd_path(args[0], envp);
	run_cmd(path, args, envp);
}

void	execute_builtin(char **args, char **envp)
{
	if (ft_strcmp(args[0], "cd") == 0)
		change_directory(args, envp);
}
