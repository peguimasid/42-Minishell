/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 11:17:14 by gmasid            #+#    #+#             */
/*   Updated: 2022/11/26 11:56:07 by gmasid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	**lexer(char **args, t_data *data)
{
	args = split_quotes(data->input, " ");
	if (!args)
		return (NULL);
	expand_args(args, data);
	// TODO: Call cmd_subsplit
	return (args);
}
