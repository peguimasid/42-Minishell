/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucafern <lucafern@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 12:20:56 by gmasid            #+#    #+#             */
/*   Updated: 2022/12/01 12:41:23 by lucafern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	print_error(char *error)
{
	ft_putstr_fd("\033[0;31m\n", 2);
	ft_putstr_fd(error, 2);
	ft_putstr_fd("\033[0m", 2);
}

int	throw_error(int err_type, int error_code, char *message)
{
	extern int	g_status;

	g_status = error_code;
	if (err_type == FORKERR)
		print_error("minishell: fork failed\n");
	if (err_type == QUOTE)
		print_error("minishell: not found matching quote\n");
	if (err_type == PIPENDERR)
		print_error("minishell: syntax error near unexpected token `|'\n");
	print_error(message);
	return (1);
}
