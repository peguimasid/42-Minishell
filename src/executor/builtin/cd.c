/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 16:50:58 by gmasid            #+#    #+#             */
/*   Updated: 2022/12/09 19:04:48 by gmasid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	handle_set_pwd_vars(t_data *data)
{
	char	*cwd;
	char	*current_pwd;

	cwd = getcwd(NULL, 0);
	current_pwd = get_env("PWD", data->envp, 3);
	set_env("OLDPWD", current_pwd, data->envp);
	set_env("PWD", cwd, data->envp);
	free(current_pwd);
	free(cwd);
}

int	handle_change_dir_to_home(t_data *data)
{
	char	*home;

	home = get_env("HOME", data->envp, 4);
	if (!home)
		return (throw_error(0, 1, "minishell: cd: HOME not set"));
	if (chdir(home) != 0)
		perror("Error");
	free(home);
	handle_set_pwd_vars(data);
	return (1);
}

int	handle_change_dir(t_cmd *cmd, t_data *data)
{
	if (chdir(cmd->full_cmd[1]) != 0)
		printf("%s: %s\n", strerror(errno), cmd->full_cmd[1]);
	handle_set_pwd_vars(data);
	return (1);
}

int	execute_cd(t_cmd *cmd, t_data *data)
{
	if (!cmd->full_cmd[1])
		return (handle_change_dir_to_home(data));
	return (handle_change_dir(cmd, data));
}

int	is_cd(t_cmd *node)
{
	char	*cmd;

	cmd = node->full_cmd[0];
	if (!cmd)
		return (0);
	if (ft_strncmp(cmd, "cd", ft_strlen(cmd)) == 0 && ft_strlen(cmd) == 2)
		return (1);
	return (0);
}
