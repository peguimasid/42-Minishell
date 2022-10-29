/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucafern <lucafern@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 09:08:14 by gmasid            #+#    #+#             */
/*   Updated: 2022/10/29 17:57:38 by lucafern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	init_env(t_data *data, char **env)
{
	int		i;
	char	**line_split;
	char	*key;
	char	*value;

	(void)data;
	i = 0;
	while (env[i])
	{
		line_split = ft_split(env[i], '=');
		key = line_split[0];
		value = line_split[1];
		set_env(data, key, value);
		free(line_split);
		i++;
	}
}
