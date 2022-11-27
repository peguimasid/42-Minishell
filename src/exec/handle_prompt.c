/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_prompt.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucafern <lucafern@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 19:34:08 by gmasid            #+#    #+#             */
/*   Updated: 2022/11/27 12:22:01 by lucafern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	parse_envs(t_data *data, char **args)
{
	int		i;
	char	*key;
	char	*value;

	i = 0;
	while (args[i])
	{
		if (args[i][0] == '$')
		{
			key = ft_substr(args[i], str_ichr(args[i], '$') + 1,
					ft_strlen(args[i]));
			value = ft_strdup(get_env(data, key));
			free(args[i]);
			args[i] = value;
		}
		i++;
	}
}

void	handle_prompt(t_data *data, char **envp)
{
	char	**args;

	if (ft_strcmp(data->command, "") == 0)
		return ;
	args = parse_command(data);
	add_history(data->command);
	parse_envs(data, args);
	if (ft_strcmp(args[0], "exit") == 0)
	{
		data->running = false;
		free_env(data);
		rl_clear_history();
		free_args(args);
		return ;
	}
	if (is_builtin(args))
	{
		execute_builtin(data, args, envp);
		free_args(args);
		return ;
	}
	if (ft_strcmp(args[0], "export") == 0)
	{
		export_env(data, args);
		free_args(args);
		return ;
	}
	execute_bin(data, args, envp);
	free_args(args);
}
