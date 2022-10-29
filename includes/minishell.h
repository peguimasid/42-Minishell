/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 15:16:25 by gmasid            #+#    #+#             */
/*   Updated: 2022/10/29 12:49:45 by gmasid           ###   ########.fr       */
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
	t_env			*env;
}					t_data;

// minishell.c
void				launch(t_data *data, char **env);

// common.c
int					throw_error(char *error);

// handle_prompt.c
void				handle_prompt(t_data *data, char **envp);

// parse.c
char				**parse_command(t_data *data);

// utils.c
int					str_ichr(char *str, char c);
int					ft_strcmp(const char *s1, const char *s2);

// builtins/cd.c
void				change_directory(char **args, char **envp);

// builtins/utils.c
bool				is_builtin(char **args);

// exec/find_path.c
char				*find_cmd_path(char *cmd, char **env);

// exec/run_cmd.c
void				run_cmd(char *path, char **cmd, char **env);

// exec/execute.c
void				execute_bin(char **args, char **envp);
void				execute_builtin(char **args, char **envp);

// env/init.c
void				init_env(t_data *data, char **env);

// env/read.c
// Change
char				*get_env_struct(t_data *data, char *key);
char				*get_env(char **env, const char *var);
void				print_env(t_data *data);
bool				env_exists(t_data *data, char *key);

// env/write.c
void				set_env(t_data *data, char *key, char *value);

#endif
