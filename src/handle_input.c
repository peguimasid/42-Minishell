/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 16:35:26 by gmasid            #+#    #+#             */
/*   Updated: 2022/11/29 14:50:43 by gmasid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	handle_input(t_data *data)
{
	char	**args;

	args = NULL;
	if (is_invalid_input(data->input))
		return (get_invalid_input_status(data->input));
	add_history(data->input);
	args = lexer(args, data);
	if (!args)
		return (throw_error(QUOTE, 1, NULL));
	parse_args(args, data);
	free_matrix(args);
	free(data->input);
	return (1);
}
