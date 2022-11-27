/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucafern <lucafern@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 19:52:05 by gmasid            #+#    #+#             */
/*   Updated: 2022/10/29 17:03:58 by lucafern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

bool	is_builtin(char **args)
{
	if (ft_strcmp(args[0], "cd") == 0)
		return (true);
	if (ft_strcmp(args[0], "env") == 0)
		return (true);
	return (false);
}
