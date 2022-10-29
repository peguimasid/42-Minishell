/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 09:08:14 by gmasid            #+#    #+#             */
/*   Updated: 2022/10/29 12:27:24 by gmasid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

bool	env_exists(t_data *data, char *key)
{
	t_env	*curr;

	curr = data->env;
	while (curr)
	{
		if (curr->key == key)
			return (true);
		curr = curr->next;
	}
	return (false);
}

// char	*get_env(t_data *data, char *key)
// {
// 	t_env	*curr;

// 	if (!env_exists(data, key))
// 		return (NULL);
// 	curr = data->env;
// 	while (curr->key != key)
// 		curr = curr->next;
// 	return (curr->value);
// }

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
