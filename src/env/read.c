/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 09:08:14 by gmasid            #+#    #+#             */
/*   Updated: 2022/10/29 12:59:27 by gmasid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

bool	env_exists(t_data *data, char *key)
{
	t_env	*curr;

	curr = data->env;
	while (curr)
	{
		if (ft_strcmp(curr->key, key) == 0)
			return (true);
		curr = curr->next;
	}
	return (false);
}

char	*get_env(t_data *data, char *key)
{
	t_env	*curr;

	if (!env_exists(data, key))
		return (NULL);
	curr = data->env;
	while (ft_strcmp(curr->key, key) != 0)
		curr = curr->next;
	return (curr->value);
}

void	print_env(t_data *data)
{
	t_env	*curr;

	curr = data->env;
	while (curr)
	{
		printf("%s=%s\n", curr->key, curr->value);
		curr = curr->next;
	}
}
