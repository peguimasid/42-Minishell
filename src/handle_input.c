/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 16:35:26 by gmasid            #+#    #+#             */
/*   Updated: 2022/11/25 14:45:49 by gmasid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	expand_args(char **args, t_data *data)
{
	int	i;

	i = 0;
	while (args[i])
	{
		args[i] = expand_vars(args[i], data);
		i++;
	}
}

void	print_args(char **args)
{
	int	i;

	i = 0;
	while (args[i])
		printf(">> %s\n", args[i++]);
}

int	handle_input(t_data *data)
{
	char	**args;

	if (!data->input)
		return (0);
	save_history(data->input);
	args = split_quotes(data->input, " ");
	if (!args)
		return (throw_error(QUOTE, 1, NULL));
	expand_args(args, data);
	print_args(args);
	return (1);
}
