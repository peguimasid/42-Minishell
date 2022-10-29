/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_prompt.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 19:34:08 by gmasid            #+#    #+#             */
/*   Updated: 2022/10/29 09:25:47 by gmasid           ###   ########.fr       */
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
		return ;
	}
	if (is_builtin(args))
	{
		execute_builtin(args, envp);
		return ;
	}
	execute_bin(args, envp);
}
