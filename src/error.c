/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 12:20:56 by gmasid            #+#    #+#             */
/*   Updated: 2022/12/06 14:10:04 by gmasid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	print_error(char *error)
{
	ft_putstr_fd("\033[0;31m", 2);
	ft_putstr_fd(error, 2);
	ft_putstr_fd("\033[0m", 2);
}

int	throw_error(int err_type, int error_code, char *message)
{
	g_status = error_code;
	if (err_type == FORKERR)
		print_error("minishell: fork failed");
	if (err_type == QUOTE)
		print_error("minishell: not found matching quote");
	if (err_type == PIPENDERR)
		print_error("minishell: syntax error near unexpected token `|'");
	if (err_type == OPENFILEERR)
		print_error("minishell: syntax error near unexpected token `newline'");
	if (err_type == NDIR)
		print_error("minishell: No such file or directory: ");
	if (err_type == NPERM)
		print_error("minishell: permission denied: ");
	if (err_type == PIPERR)
		print_error("minishell: error creating pipe");
	if (err_type == IS_DIR)
		print_error("minishell: Is a directory: ");
	if (err_type == NOTFOUNDCMD)
		print_error("minishell: command not found: ");
	print_error(message);
	ft_putstr_fd("\n", 2);
	return (1);
}
