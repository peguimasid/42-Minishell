/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 15:16:25 by gmasid            #+#    #+#             */
/*   Updated: 2022/11/15 14:40:22 by gmasid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../lib/libft/libft.h"
# include <limits.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <string.h>
# include <sys/errno.h>
# include <sys/wait.h>

# define DEFAULT_PATH "/usr/local/sbin:/usr/local/bin:/usr/bin:/bin"

typedef struct s_data
{
	char	*input;
	char	**envp;
	int		running;
	t_list	*cmds;
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

// handle_input.c
int			handle_input(t_data *data);

// split_quotes.c
char		**split_quotes(char const *s, char *set);

// free.c
void		free_data(t_data *data);

// ------------------- UTILS -------------------

// matrix
char		**dup_matrix(char **matrix);
char		**matrix_push(char **matrix, char *new);
char		**matrix_replace(char **matrix, int i, char *new_value);
int			matrix_len(char **matrix);
void		free_matrix(char **matrix);

// env
int			get_env_index(char *key, char **envp);
char		*get_env(char *key, char **envp);
char		**set_env(char *key, char *value, char **envp);

void		init_pwd(t_data *data);
void		init_shlvl(t_data *data);
void		init_path(t_data *data);
void		init_executable(t_data *data, char *program_name);

// clear_window
void		clear_window(void);

#endif
