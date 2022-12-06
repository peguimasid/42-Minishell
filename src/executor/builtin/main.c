/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 18:18:27 by gmasid            #+#    #+#             */
/*   Updated: 2022/12/06 12:26:19 by gmasid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

int	handle_config_builtin(t_cmd *cmd, t_data *data)
{
	// TODO: Execute: cd, export, unset
	(void)data;
	if (is_exit(cmd))
		return (execute_exit(cmd));
	printf("Change config\n");
	printf("command => %s\n\n", *cmd->full_cmd);
	return (1);
}
