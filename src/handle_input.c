/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 16:35:26 by gmasid            #+#    #+#             */
/*   Updated: 2022/11/15 14:40:32 by gmasid           ###   ########.fr       */
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
	char	**list;

	if (!data->input)
		return (0);
	add_history(data->input);
	list = split_quotes(data->input, " ");
	print_lst(list);
	free(data->input);
	return (1);
}
