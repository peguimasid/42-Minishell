/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 12:20:56 by gmasid            #+#    #+#             */
/*   Updated: 2022/11/15 14:52:30 by gmasid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	throw_error(int err_type, int error_code, char *message)
{
	g_status = error_code;
	if (err_type == FORKERR)
		ft_putstr_fd("minishell: fork failed\n", 2);
	if (err_type == QUOTE)
		ft_putstr_fd("minishell: not found matching quote\n", 2);
	ft_putstr_fd(message, 2);
	return (1);
}
