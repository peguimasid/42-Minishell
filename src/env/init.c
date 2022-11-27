/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucafern <lucafern@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 09:08:14 by gmasid            #+#    #+#             */
/*   Updated: 2022/10/29 19:44:16 by lucafern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	init_env(t_data *data, char **env)
{
	int		i;
	char	*key;
	char	*value;

	(void)data;
	i = 0;
	while (env[i])
	{
		key = ft_substr(env[i], 0, str_ichr(env[i], '='));
		value = ft_substr(env[i], str_ichr(env[i], '=') + 1, ft_strlen(env[i]));
		set_env(data, key, value);
		i++;
	}
}
