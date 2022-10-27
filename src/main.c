/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucafern <lucafern@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 17:31:19 by gmasid            #+#    #+#             */
/*   Updated: 2022/10/27 18:19:16 by lucafern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	main(int argc, char **argv, char **env)
{
	t_data	data;

	if (argc != 1 || argv[1] != NULL)
		return (throw_error("This program accepts no arguments"));
	init_data(&data);
	while (data.running)
	{
		data.command = readline("Minishell ▸ ");
		add_history(data.command);
		handle_prompt(&data, env);
	}
	return (0);
}
