/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 15:16:25 by gmasid            #+#    #+#             */
/*   Updated: 2022/10/26 12:05:20 by gmasid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../lib/libft/libft.h"
# include <limits.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <stdio.h>
# include <string.h>
# include <sys/errno.h>

# define TRUE 1
# define FALSE 0

typedef struct s_data
{
	int		running;
	char	*command;
}			t_data;

// init.c
void		init_data(t_data *data);

// run_cmd.c
void		execute_bin(char **args, char **envp);

// builtins/main.c
void		execute_builtin(char **args, char **envp);

// builtins/env.c
char		*get_env(char **env, const char *var);

// handle_prompt.c
void		handle_prompt(t_data *data, char **envp);

// parse.c
char		**parse_command(t_data *data);

// utils.c
int			str_ichr(char *str, char c);
int			ft_strcmp(const char *s1, const char *s2);

// builtins/utils.c
int			is_builtin(char **args);

#endif
