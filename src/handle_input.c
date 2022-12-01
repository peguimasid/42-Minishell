/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucafern <lucafern@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 16:35:26 by gmasid            #+#    #+#             */
/*   Updated: 2022/12/01 13:28:20 by lucafern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	handle_input(t_data *data)
{
	if (is_invalid_input(data->input))
		return (get_invalid_input_status(data->input));
	add_history(data->input);
	if (!lexer(data))
		return (throw_error(QUOTE, 1, NULL));
	parse_args(data);
	handle_cmds(data);
	clean(data);
	return (1);
}
