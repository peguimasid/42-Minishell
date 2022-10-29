/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 15:16:25 by gmasid            #+#    #+#             */
/*   Updated: 2022/10/29 08:56:34 by gmasid           ###   ########.fr       */
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
# include <stdio.h>
# include <string.h>
# include <sys/errno.h>
# include <sys/wait.h>

typedef struct s_env
{
	char			*key;
	char			*value;
	struct s_env	*next;
}					t_env;

typedef struct s_data
{
	bool			running;
	char			*command;
}					t_data;

// minishell.c
void				lounch(t_data *data);

// common.c
int					throw_error(char *error);

// run_cmd.c
void				execute_bin(char **args, char **envp);

// handle_prompt.c
void				handle_prompt(t_data *data, char **envp);

// parse.c
char				**parse_command(t_data *data);

// utils.c
int					str_ichr(char *str, char c);
int					ft_strcmp(const char *s1, const char *s2);

// builtins/main.c
void				execute_builtin(char **args, char **envp);

// builtins/env.c
char				*get_env(char **env, const char *var);

// builtins/cd.c
void				change_directory(char **args, char **env);

// builtins/utils.c
bool				is_builtin(char **args);

#endif
