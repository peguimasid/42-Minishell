/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 18:14:14 by gmasid            #+#    #+#             */
/*   Updated: 2022/12/05 18:25:50 by gmasid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

int	has_next(t_list *node)
{
	return (node->next != NULL);
}

void	wait_child_processes_exit(t_data *data)
{
	int	i;

	i = 0;
	while (i < ft_lstsize(data->cmds))
	{
		waitpid(-1, &g_status, 0);
		i++;
	}
}
