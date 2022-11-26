/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 11:17:14 by gmasid            #+#    #+#             */
/*   Updated: 2022/11/26 12:33:08 by gmasid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	**lexer(char **args, t_data *data)
{
	args = split_quotes(data->input, " ");
	if (!args)
		return (NULL);
	expand_args(args, data);
	args = subsplit_pipes_and_redirections(args);
	return (args);
}
