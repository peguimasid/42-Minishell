/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucafern <lucafern@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 15:26:01 by lucafern          #+#    #+#             */
/*   Updated: 2022/11/01 16:05:44 by lucafern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	export_env(t_data *data, char **args)
{
	char	*key;
	char	*value;

	key = ft_substr(args[1], 0, str_ichr(args[1], '='));
	value = ft_substr(args[1], str_ichr(args[1], '=') + 1, ft_strlen(args[1]));
	set_env(data, key, value);
}
