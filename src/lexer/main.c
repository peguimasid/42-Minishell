/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 11:17:14 by gmasid            #+#    #+#             */
/*   Updated: 2022/11/29 15:14:45 by gmasid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	lexer(t_data *data)
{
	data->args = split_quotes(data->input, " ");
	if (!data->args)
	{
		free(data->input);
		return (0);
	}
	expand_args(data->args, data);
	data->args = subsplit_pipes_and_redirections(data->args);
	return (1);
}
