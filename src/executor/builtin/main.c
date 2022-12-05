/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 18:18:27 by gmasid            #+#    #+#             */
/*   Updated: 2022/12/05 19:13:07 by gmasid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

int	handle_config_builtin(t_cmd *cmd)
{
	// TODO: Execute: cd, export, unset
	if (is_exit(cmd))
		return (execute_exit(cmd));
	printf("Change config\n");
	printf("command => %s\n\n", *cmd->full_cmd);
	return (1);
}
