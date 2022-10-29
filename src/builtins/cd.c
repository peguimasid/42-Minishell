/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucafern <lucafern@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 12:46:30 by gmasid            #+#    #+#             */
/*   Updated: 2022/10/29 20:26:51 by lucafern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	update_pwd(t_data *data, char *new_path)
{
	set_env(data, "OLDPWD", ft_strdup(get_env(data, "PWD")));
	set_env(data, "PWD", ft_strdup(new_path));
}

void	change_directory(t_data *data, char **args)
{
	char	*path;
	char	cwd[PATH_MAX];

	if (!args[1])
	{
		path = get_env(data, "HOME");
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
	getcwd(cwd, sizeof(cwd));
	update_pwd(data, cwd);
}
