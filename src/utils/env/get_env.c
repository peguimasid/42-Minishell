/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 11:49:11 by gmasid            #+#    #+#             */
/*   Updated: 2022/11/07 18:17:35 by gmasid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	get_env(char *key, char **envp)
{
	(void)key;
	(void)envp;
	// TODO: Receive envs and find by key
	// Use ft_strncmp but make sure that envp[i][ft_strlen(key)] == '='
}

int	get_env_index(char *key, char **envp)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(key);
	while (envp[i])
	{
		if (ft_strncmp(key, envp[i], len) == 0 && envp[i][len] == '=')
			return (i);
		i++;
	}
	return (-1);
}
