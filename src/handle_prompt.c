/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_prompt.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 19:34:08 by gmasid            #+#    #+#             */
/*   Updated: 2022/10/26 11:48:17 by gmasid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	handle_prompt(t_data *data, char **envp)
{
	char	**args;

	args = parse_command(data);
	if (ft_strcmp(args[0], "exit") == 0)
	{
		data->running = FALSE;
		return ;
	}
	if (is_builtin(args))
	{
		execute_builtin(args, envp);
		return ;
	}
	execute_bin(args, envp);
}
