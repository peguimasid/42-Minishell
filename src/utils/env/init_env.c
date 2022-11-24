/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 18:36:42 by gmasid            #+#    #+#             */
/*   Updated: 2022/11/24 12:49:03 by gmasid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	init_pwd(t_data *data)
{
	char	*current_dir;

	current_dir = getcwd(NULL, 0);
	data->envp = set_env("PWD", current_dir, data->envp);
	free(current_dir);
}

void	init_shlvl(t_data *data)
{
	char	*current_shlvl;
	char	*previous_shlvl;

	previous_shlvl = get_env("SHLVL", data->envp);
	if (!previous_shlvl || ft_atoi(previous_shlvl) <= 0)
		current_shlvl = ft_strdup("1");
	else
		current_shlvl = ft_itoa(ft_atoi(previous_shlvl) + 1);
	data->envp = set_env("SHLVL", current_shlvl, data->envp);
	free(current_shlvl);
	free(previous_shlvl);
}

void	init_path(t_data *data)
{
	char	*current_path;

	current_path = get_env("PATH", data->envp);
	if (!current_path)
	{
		data->envp = set_env("PATH", DEFAULT_PATH, data->envp);
		return ;
	}
	free(current_path);
}

void	init_executable(t_data *data, char *program_name)
{
	data->envp = set_env("_", program_name, data->envp);
}
