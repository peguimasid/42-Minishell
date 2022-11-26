/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 11:17:14 by gmasid            #+#    #+#             */
/*   Updated: 2022/11/26 11:54:32 by gmasid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	expand_args(char **args, t_data *data)
{
	int	i;

	i = 0;
	while (args[i])
	{
		args[i] = expand_vars(args[i], data);
		args[i] = expand_path(args[i], data);
		i++;
	}
}

char	**lexer(char **args, t_data *data)
{
	args = split_quotes(data->input, " ");
	if (!args)
		return (NULL);
	expand_args(args, data);
	// TODO: Call cmd_subsplit
	return (args);
}
