/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucafern <lucafern@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 09:08:14 by gmasid            #+#    #+#             */
/*   Updated: 2022/11/01 14:29:21 by lucafern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	change_env_value(t_data *data, char *key, char *value)
{
	t_env	*curr;

	curr = data->env;
	while (ft_strcmp(curr->key, key) != 0)
		curr = curr->next;
	free(curr->key);
	curr->key = key;
	free(curr->value);
	curr->value = value;
}

void	add_new_env(t_data *data, char *key, char *value)
{
	t_env	*curr;

	if (!data->env)
	{
		data->env = malloc(sizeof(t_env));
		data->env->key = key;
		data->env->value = value;
		data->env->next = NULL;
		return ;
	}
	curr = data->env;
	while (curr->next)
		curr = curr->next;
	curr->next = malloc(sizeof(t_env));
	curr->next->key = key;
	curr->next->value = value;
	curr->next->next = NULL;
}

void	set_env(t_data *data, char *key, char *value)
{
	if (env_exists(data, key))
		return (change_env_value(data, key, value));
	return (add_new_env(data, key, value));
}
