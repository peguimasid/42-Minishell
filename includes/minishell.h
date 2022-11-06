/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 15:16:25 by gmasid            #+#    #+#             */
/*   Updated: 2022/11/06 13:15:36 by gmasid           ###   ########.fr       */
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

enum		e_error_type
{
	FORKERR = 1,
};

int			g_status;

// minishell.c
int			minishell(char **argv, char **envp);

// signal.c
void		handle_sigint(int sig);
void		set_default_signal_handlers(void);

// common.c
int			throw_error(int err_type, int error_code, char *message);

// ------------------- UTILS -------------------

// matrix
char		**dup_matrix(char **matrix);
char		**matrix_push(char **matrix, char *new);
int			matrix_len(char **matrix);
void		free_matrix(char **matrix);

// env
char		**set_env(char *key, char *value, char **envp);

#endif
