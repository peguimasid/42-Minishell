/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 15:16:25 by gmasid            #+#    #+#             */
/*   Updated: 2022/10/25 20:00:07 by gmasid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../lib/libft/libft.h"
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <stdbool.h>
# include <stdio.h>

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
int			execute_builtin(char **args, char **envp);

// handle_prompt.c
void		handle_prompt(t_data *data, char **envp);

// parse.c
char		**parse_command(t_data *data);

// utils.c
int			str_ichr(char *str, char c);
int			ft_strcmp(const char *s1, const char *s2);

// builtins/utils.c
bool		is_builtin(char **args);

#endif
