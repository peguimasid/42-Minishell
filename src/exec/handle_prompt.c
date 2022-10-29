/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_prompt.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucafern <lucafern@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 19:34:08 by gmasid            #+#    #+#             */
/*   Updated: 2022/10/29 19:28:39 by lucafern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	handle_prompt(t_data *data, char **envp)
{
	char	**args;

	if (ft_strcmp(data->command, "") == 0)
		return ;
	args = parse_command(data);
	add_history(data->command);
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
	execute_bin(data, args, envp);
	free_args(args);
}
