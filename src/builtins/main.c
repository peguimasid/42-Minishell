/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 19:52:34 by gmasid            #+#    #+#             */
/*   Updated: 2022/10/26 11:59:56 by gmasid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	change_directory(char **args, char **env)
{
	char	*path;
	char	cwd[PATH_MAX];

	getcwd(cwd, sizeof(cwd));
	if (!args[1])
	{
		path = get_env(env, "HOME");
		if (chdir(path) != 0)
			perror("Error");
		return ;
	}
	if (args[2])
	{
		printf("cd: string not in pwd: %s\n", args[1]);
		return ;
	}
	if (chdir(args[1]) != 0)
		perror("Error");
}

void	execute_builtin(char **args, char **envp)
{
	if (ft_strcmp(args[0], "cd") == 0)
		change_directory(args, envp);
}
