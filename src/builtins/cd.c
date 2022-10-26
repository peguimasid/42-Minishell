/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 12:46:30 by gmasid            #+#    #+#             */
/*   Updated: 2022/10/26 12:46:42 by gmasid           ###   ########.fr       */
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
		printf("%s: %s\n", strerror(errno), args[1]);
}