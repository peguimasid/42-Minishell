/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucafern <lucafern@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 08:50:30 by gmasid            #+#    #+#             */
/*   Updated: 2022/11/26 12:41:58 by lucafern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	launch(t_data *data, char **env)
{
	(void)env;
	while (data->running)
	{
		data->command = readline("Minishell ⇢ ");
		handle_prompt(data, env);
		free(data->command);
	}
}
