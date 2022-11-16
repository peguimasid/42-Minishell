/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 16:35:26 by gmasid            #+#    #+#             */
/*   Updated: 2022/11/16 12:49:54 by gmasid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	print_lst(char **vec)
{
	int	i;

	i = 0;
	while (vec && vec[i])
		printf(">> %s\n", vec[i++]);
}

int	handle_input(t_data *data)
{
	char	**args;

	if (!data->input)
		return (0);
	add_history(data->input);
	args = split_quotes(data->input, " ");
	print_lst(args);
	free(data->input);
	if (!args)
		return (throw_error(QUOTE, 1, NULL));
	return (1);
}
