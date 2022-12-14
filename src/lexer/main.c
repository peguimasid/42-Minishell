/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucafern <lucafern@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
<<<<<<< HEAD:src/exec/run_cmd.c
/*   Created: 2022/10/29 09:19:17 by gmasid            #+#    #+#             */
/*   Updated: 2022/10/29 17:05:05 by lucafern         ###   ########.fr       */
=======
/*   Created: 2022/11/26 11:17:14 by gmasid            #+#    #+#             */
/*   Updated: 2022/11/29 15:14:45 by gmasid           ###   ########.fr       */
>>>>>>> 94d5e82586533380ec0faa173c0bd303ef15f2b8:src/lexer/main.c
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	lexer(t_data *data)
{
	data->args = split_quotes(data->input, " ");
	if (!data->args)
	{
		free(data->input);
		return (0);
	}
	expand_args(data->args, data);
	data->args = subsplit_pipes_and_redirections(data->args);
	return (1);
}
