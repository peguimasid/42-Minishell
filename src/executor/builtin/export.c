/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 21:48:12 by gmasid            #+#    #+#             */
/*   Updated: 2022/12/09 22:29:49 by gmasid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

int	export_error(char *variable)
{
	char	*error_msg;
	char	*aux;

	aux = ft_strdup("minishell: export: `");
	error_msg = ft_strjoin(NULL, aux);
	free(aux);
	error_msg = ft_strjoin(error_msg, variable);
	aux = ft_strdup("': not a valid identifier");
	error_msg = ft_strjoin(error_msg, aux);
	free(aux);
	throw_error(0, 1, error_msg);
	free(error_msg);
	return (1);
}

int	execute_export(t_cmd *cmd, t_data *data)
{
	char	*variable_joined;
	int		equal_sign_index;
	int		to_copy;
	char	*key;
	char	*value;

	if (!cmd || !cmd->full_cmd[1])
		return (1);
	variable_joined = cmd->full_cmd[1];
	equal_sign_index = ft_strchars_i(variable_joined, "=");
	if (equal_sign_index == -1)
		return (1);
	if (equal_sign_index == 0)
		return (export_error(variable_joined));
	to_copy = ft_strlen(variable_joined) - equal_sign_index;
	key = ft_substr(variable_joined, 0, equal_sign_index);
	value = ft_substr(variable_joined, equal_sign_index + 1, to_copy);
	data->envp = set_env(key, value, data->envp);
	return (1);
}

int	is_export(t_cmd *node)
{
	char	*cmd;

	cmd = node->full_cmd[0];
	if (!cmd)
		return (0);
	if (ft_strncmp(cmd, "export", ft_strlen(cmd)) == 0 && ft_strlen(cmd) == 6)
		return (1);
	return (0);
}
