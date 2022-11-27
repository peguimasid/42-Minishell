/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucafern <lucafern@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 13:49:30 by gmasid            #+#    #+#             */
/*   Updated: 2022/10/29 18:46:08 by lucafern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	execute_bin(t_data *data, char **args, char **envp)
{
	char	*path;

	if (str_ichr(args[0], '/') > -1)
		path = args[0];
	else
		path = find_cmd_path(data, args[0]);
	run_cmd(path, args, envp);
	free(path);
}

void	execute_builtin(t_data *data, char **args, char **envp)
{
	(void)envp;
	if (ft_strcmp(args[0], "cd") == 0)
		change_directory(data, args);
	if (ft_strcmp(args[0], "env") == 0)
		print_env(data);
}
