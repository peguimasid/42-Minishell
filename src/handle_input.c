/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 16:35:26 by gmasid            #+#    #+#             */
/*   Updated: 2022/11/24 12:53:06 by gmasid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	handle_input(t_data *data)
{
	char	**args;

	if (!data->input)
		return (0);
	save_history(data->input);
	args = split_quotes(data->input, " ");
	printf(">> %s\n", expand_vars("Hello $NAME", data));
	free(data->input);
	if (!args)
		return (throw_error(QUOTE, 1, NULL));
	return (1);
}
