/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 17:31:19 by gmasid            #+#    #+#             */
/*   Updated: 2022/10/29 12:32:03 by gmasid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	init_data(t_data *data, char **env)
{
	data->running = true;
	data->command = NULL;
	data->env = NULL;
	init_env(data, env);
}

int	main(int argc, char **argv, char **env)
{
	t_data	data;

	(void)argv;
	(void)env;
	if (argc != 1)
		return (throw_error("This program accepts no arguments"));
	init_data(&data, env);
	launch(&data, env);
	return (0);
}
