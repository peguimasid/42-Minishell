/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 15:16:25 by gmasid            #+#    #+#             */
/*   Updated: 2022/11/05 13:58:54 by gmasid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../lib/libft/libft.h"
# include <limits.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <stdbool.h>
# include <string.h>
# include <sys/errno.h>
# include <sys/wait.h>

typedef struct s_data
{
	t_list	*cmds;
	char	**envp;
	pid_t	pid;
}			t_data;

int			g_status;

// minishell.c
void		minishell(int argc, char **argv, char **envp);

// signal.c
void		handle_sigint(int sig);

// common.c
int			throw_error(char *error);

// ------------------- UTILS -------------------

// matrix
char		**dup_matrix(char **matrix);
int			matrix_len(char **matrix);
void		free_matrix(char **matrix);

#endif
