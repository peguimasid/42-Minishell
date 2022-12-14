/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 16:35:26 by gmasid            #+#    #+#             */
/*   Updated: 2022/12/09 22:46:42 by gmasid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	handle_input(t_data *data)
{
	int	status;

	status = 1;
	if (is_invalid_input(data->input))
		return (get_invalid_input_status(data->input));
	add_history(data->input);
	if (!lexer(data))
		return (throw_error(QUOTE, 1, NULL));
	parse_args(data);
	status = executor(data);
	clean(data);
	return (status);
}
