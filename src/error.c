/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 12:20:56 by gmasid            #+#    #+#             */
/*   Updated: 2022/11/05 21:10:26 by gmasid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	throw_error(int err_type, int error_code, char *message)
{
	g_status = error_code;
	if (err_type == FORKERR)
		ft_putstr_fd("minishell: fork failed\n", 2);
	ft_putstr_fd(message, 2);
	return (1);
}
