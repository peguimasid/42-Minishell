/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constants.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 13:44:40 by gmasid            #+#    #+#             */
/*   Updated: 2022/12/03 18:06:30 by gmasid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONSTANTS_H
# define CONSTANTS_H

# define DEFAULT_PATH "/usr/local/sbin:/usr/local/bin:/usr/bin:/bin"
# define HDOC_WARN "minishell: warning: here-document delimited by end-of-file"
# define SINGLE_QUOTE '\''
# define DOUBLE_QUOTE '\"'
# define READ_END 0
# define WRITE_END 1

enum		e_error_type
{
	FORKERR = 10,
	QUOTE = 11,
	PIPENDERR = 12,
	OPENFILEERR = 13,
	NDIR = 14,
	NPERM = 15,
	PIPERR = 16,
};

enum		e_redirection_type
{
	REDIRECT_INPUT = 1000,
	REDIRECT_OUTPUT = 1001,
	APPEND_OUTPUT = 1002,
	HEREDOC = 1003,
	PIPE = 1004,
	NORMAL_ARG = 1005,
	NO_ARG = 1404,
};

#endif
