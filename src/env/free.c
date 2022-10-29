/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucafern <lucafern@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 17:25:41 by lucafern          #+#    #+#             */
/*   Updated: 2022/10/29 18:03:57 by lucafern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	free_env(t_data *data)
{
	t_env	*curr;
	t_env	*to_free;

	curr = data->env;
	while (curr)
	{
		to_free = curr;
		curr = curr->next;
		free(to_free->key);
		free(to_free->value);
		free(to_free);
	}
}
