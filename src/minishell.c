/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 08:50:30 by gmasid            #+#    #+#             */
/*   Updated: 2022/10/29 08:52:38 by gmasid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	lounch(t_data *data)
{
	while (data->running)
	{
		data->command = readline("Minishell ▸ ");
		printf("command was = %s\n", data->command);
		// handle_prompt(&data, env);
	}
}