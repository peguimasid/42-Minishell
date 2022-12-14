/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucafern <lucafern@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 15:16:25 by gmasid            #+#    #+#             */
/*   Updated: 2022/12/14 09:12:02 by lucafern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../lib/libft/libft.h"
# include "constants.h"
# include <dirent.h>
# include <fcntl.h>
# include <limits.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <string.h>
# include <sys/errno.h>
# include <sys/ioctl.h>
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

extern int	g_status;

// minishell.c
int			minishell(char **argv, char **envp);

// signal.c
void		handle_sigint(int sig);
void		set_default_signal_handlers(void);
void		set_child_process_signal_handlers(void);

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

// utils.c
char		*get_substr_var(char *str, int i, t_data *data);
char		*get_substr_path(char *str, int i, t_data *data);

// ------------------ PARSER -------------------

// main.c
void		parse_args(t_data *data);

// trim_args.c
char		**trim_args(char **args);

// fill_nodes.c
void		fill_nodes(t_data *data);

// get_file_descriptors.c
int			set_outfile_fd(t_cmd *node, char **args, int i);
int			set_append_outfile_fd(t_cmd *node, char **args, int i);
int			set_infile_fd(t_cmd *node, char **args, int i);
int			set_heredoc_fd(t_cmd *node, char **args, int i);

// heredoc.c
int			get_heredoc(char *delimiter);

// utils.c
int			get_argument_type(char **args, int i);
int			empty_pipe_error(void);
int			empty_redirection_error(void);
void		quit_parsing(t_data *data);
t_cmd		*new_node(void);

// ----------------- EXECUTOR ------------------

// main.c
int			executor(t_data *data);
int			execute_commands(t_data *data);

// utils.c
int			has_next(t_list *node);
void		wait_child_processes_exit(t_data *data);

// #### BUILTIN ####
int			handle_config_builtin(t_list *node, t_data *data);
int			handle_generate_output_builtin(t_list *node, t_data *data);
int			is_builtin(t_cmd *node);
int			is_config_builtin(t_cmd *node);
int			is_generate_output_builtin(t_cmd *node);

// exit.c
int			is_exit(t_cmd *node);
int			execute_exit(t_cmd *cmd);

// cd.c
int			is_cd(t_cmd *cmd);
int			execute_cd(t_cmd *cmd, t_data *data);

// env.c
int			is_env(t_cmd *cmd);
int			execute_env(t_data *data);

// echo.c
int			is_echo(t_cmd *node);
int			execute_echo(t_cmd *cmd);

// unset.c
int			is_unset(t_cmd *node);
int			execute_unset(t_cmd *cmd, t_data *data);

// pwd.c
int			is_pwd(t_cmd *node);
int			execute_pwd(void);

// export.c
int			is_export(t_cmd *node);
int			execute_export(t_cmd *cmd, t_data *data);

// #### EXTERNAL ####

// path
int			handle_generate_output(t_list *node, t_data *data);
void		handle_cmd_path(t_data *data, t_list *node);
char		*find_command_path(char *cmd, t_data *data);
char		*set_absolute_path(t_cmd *cmd);
int			check_for_errors(t_cmd *cmd);
int			is_current_folder_dir(t_cmd *cmd);
int			send_absolute_path_to_command(t_cmd *cmd);
int			send_relative_path_to_command(t_cmd *cmd);

// execute
void		execute(t_list *node, t_data *data, int fd[2]);
int			can_execute_in_child_process(t_cmd *cmd);
int			handle_redirections(t_list *node, int fd[2]);

// ------------------- UTILS -------------------

// matrix
char		**dup_matrix(char **matrix);
char		**matrix_push(char **matrix, char *new);
char		**matrix_replace(char **matrix, int i, char *new_value);
char		**matrix_remove(char **matrix, int to_remove);
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

// input
int			is_empty(char *input);
int			is_null(char *input);
int			is_invalid_input(char *input);
int			get_invalid_input_status(char *input);

// tools
int			ft_strchars_i(const char *s, char *set);
char		*ft_strcat(char *src, char *dest);
void		clear_window(void);
void		print_nodes(t_data *data);
int			restrict_atoi(const char *str);

void				free_env(t_data *data);
void				free_args(char **args);

#endif
