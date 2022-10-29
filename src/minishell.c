/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 08:50:30 by gmasid            #+#    #+#             */
/*   Updated: 2022/10/29 12:51:49 by gmasid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	launch(t_data *data, char **env)
{
	printf(">> %s", get_env_struct(data, "HOME"));
	while (data->running)
	{
		data->command = readline("Minishell ▸ ");
		// printf("command was = %s\n", data->command);
		handle_prompt(data, env);
	}
}