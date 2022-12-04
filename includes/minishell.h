/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucafern <lucafern@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 15:16:25 by gmasid            #+#    #+#             */
/*   Updated: 2022/12/04 14:05:18 by lucafern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../lib/libft/libft.h"
# include "constants.h"
# include <limits.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <string.h>
# include <sys/errno.h>
# include <sys/wait.h>

typedef struct s_data
{
	char	*input;
	char	**envp;
	int		running;
	char	**args;
	t_list	*cmds;
	pid_t	pid;
}			t_data;

typedef struct s_cmd
{
	char	**full_cmd;
	char	*cmd_path;
	int		infile;
	int		outfile;
}			t_cmd;

enum		e_error_type
{
	FORKERR = 10,
	QUOTE = 11,
	PIPENDERR = 12,
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

// minishell.c
int			minishell(char **argv, char **envp);

// signal.c
void		handle_sigint(int sig);
void		set_default_signal_handlers(void);

// common.c
int			throw_error(int err_type, int error_code, char *message);

// free.c
void		free_data(t_data *data);
void		free_node(void *node);
void		clean(t_data *data);

// handle_input.c
int			handle_input(t_data *data);

// ------------------- LEXER -------------------

int			lexer(t_data *data);
char		**split_quotes(char const *s, char *set);
char		**subsplit_pipes_and_redirections(char **args);

// ----------------- EXPANDER ------------------

// main.c
void		expand_args(char **args, t_data *data);
char		*expand_vars(char *str, t_data *data);
char		*expand_path(char *str, t_data *data);
char		*get_substr_var(char *str, int i, t_data *data);
char		*get_substr_path(char *str, int i, t_data *data);

// ------------------ PARSER -------------------

void		parse_args(t_data *data);
void		fill_nodes(t_data *data);
char		**trim_args(char **args);
t_cmd		*new_node(void);
int			get_argument_type(char **args, int i);
void		quit_parsing(t_data *data, char **trimmed_args);
int			empty_pipe_error(void);
int			set_append_output_file_fd(t_data *data, char **trimmed_args, int i);

// ------------------ EXECUTOR -------------------

int			str_ichr(char *str, char c);
void		read_from_prev_pipe(int fd[2]);
void		write_on_pipe_to_next_cmd(int fd[2], int lst_size);
void		handle_cmds(t_data *data);
char		*find_cmd_path(t_data *data, char *cmd);
void		define_cmd_path(t_cmd *cmd, t_data *data);

// ------------------- UTILS -------------------

// matrix
char		**dup_matrix(char **matrix);
char		**matrix_push(char **matrix, char *new);
char		**matrix_replace(char **matrix, int i, char *new_value);
int			matrix_len(char **matrix);
void		print_matrix(char **matrix);
void		free_matrix(char **matrix);

// env
int			get_env_index(char *key, char **envp);
char		*get_env(char *key, char **envp, int key_len);
char		**set_env(char *key, char *value, char **envp);

void		init_pwd(t_data *data);
void		init_shlvl(t_data *data);
void		init_path(t_data *data);
void		init_executable(t_data *data, char *program_name);

// clear_window
void		clear_window(void);

// input
int			is_empty(char *input);
int			is_null(char *input);
int			is_invalid_input(char *input);
int			get_invalid_input_status(char *input);

// tools
int			ft_strchars_i(const char *s, char *set);

#endif
