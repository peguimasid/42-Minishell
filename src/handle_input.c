/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 16:35:26 by gmasid            #+#    #+#             */
/*   Updated: 2022/11/26 11:38:26 by gmasid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

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

	args = NULL;
	if (!data->input)
		return (0);
	save_history(data->input);
	args = lexer(args, data);
	if (!args)
		return (throw_error(QUOTE, 1, NULL));
	print_args(args);
	return (1);
}
