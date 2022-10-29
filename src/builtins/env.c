/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 11:42:00 by gmasid            #+#    #+#             */
/*   Updated: 2022/10/29 09:00:41 by gmasid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

// TODO: Change this function to print from "t_env" struct
char	*get_env(char **env, const char *var)
{
	int		i;
	char	*path;

	i = 0;
	while (env[i] && ft_strncmp(env[i], var, ft_strlen(var)) != 0)
		i++;
	if (env[i] == NULL)
		return (NULL);
	path = env[i];
	return (path + 5);
}
