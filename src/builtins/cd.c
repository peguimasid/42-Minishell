/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucafern <lucafern@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 12:46:30 by gmasid            #+#    #+#             */
/*   Updated: 2022/11/01 14:42:19 by lucafern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	update_pwd(t_data *data)
{
	char	cwd[PATH_MAX];

	getcwd(cwd, sizeof(cwd));
	set_env(data, ft_strdup("OLDPWD"), ft_strdup(get_env(data, "PWD")));
	set_env(data, ft_strdup("PWD"), ft_strdup(cwd));
}

void	change_directory(t_data *data, char **args)
{
	char	*path;

	if (!args[1])
	{
		path = get_env(data, "HOME");
		if (chdir(path) != 0)
			perror("Error");
		update_pwd(data);
		return ;
	}
	if (args[2])
	{
		printf("cd: string not in pwd: %s\n", args[1]);
		return ;
	}
	if (chdir(args[1]) != 0)
		printf("%s: %s\n", strerror(errno), args[1]);
	update_pwd(data);
}
