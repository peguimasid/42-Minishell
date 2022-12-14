/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucafern <lucafern@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
<<<<<<< HEAD:src/builtins/utils.c
/*   Created: 2022/10/25 19:52:05 by gmasid            #+#    #+#             */
/*   Updated: 2022/10/29 17:03:58 by lucafern         ###   ########.fr       */
=======
/*   Created: 2022/12/05 18:14:14 by gmasid            #+#    #+#             */
/*   Updated: 2022/12/06 16:56:16 by gmasid           ###   ########.fr       */
>>>>>>> 94d5e82586533380ec0faa173c0bd303ef15f2b8:src/executor/utils.c
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

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
