/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 18:22:12 by gmasid            #+#    #+#             */
/*   Updated: 2022/12/06 12:25:02 by gmasid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

int	handle_generate_output(t_cmd *cmd, t_data *data)
{
	(void)data;
	printf("Generate output\n");
	printf("command => %s\n\n", *cmd->full_cmd);
	return (1);
}
