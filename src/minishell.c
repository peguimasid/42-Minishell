/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucafern <lucafern@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 08:50:30 by gmasid            #+#    #+#             */
/*   Updated: 2022/11/27 18:12:55 by lucafern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	launch(t_data *data, char **env)
{
	char	*line_orig;
	t_list	*all_cmds;
	t_list	*current_cmd;
	int		i;
	int		fd[4096][2];
	int		pid[4096];

	(void)env;
	while (data->running)
	{
		i = 0;
		all_cmds = NULL;
		line_orig = readline("Minishell ⇢ ");
		add_history(line_orig);
		all_cmds = pipe_separator(line_orig);
		current_cmd = all_cmds;
		while (i < ft_lstsize(all_cmds))
		{
			if (pipe(fd[i]) < 0)
				return ;
			pid[i] = fork();
			if (pid[i] < 0)
				return ;
			if (pid[i] == 0)
			{
				if (i > 0)
				{
					dup2(fd[i - 1][0], STDIN_FILENO);
					close(fd[i - 1][0]);
					close(fd[i - 1][1]);
					data->command = current_cmd->content;
					if (current_cmd->content)
						handle_prompt(data, env);
				}
				if (i < ft_lstsize(all_cmds))
				{
					if (ft_lstsize(all_cmds) > 1)
					{
						dup2(fd[i][1], STDOUT_FILENO);
						close(fd[i][0]);
						close(fd[i][1]);
					}
					data->command = current_cmd->content;
					if (current_cmd->content)
						handle_prompt(data, env);
				}
				return ;
			}
			current_cmd = all_cmds->next;
			i++;
		}
		i = 0;
		while (i < ft_lstsize(all_cmds))
		{
			close(fd[i][0]);
			close(fd[i][1]);
			i++;
		}
		i = 0;
		while (i < ft_lstsize(all_cmds))
			waitpid(pid[i++], NULL, 0);
		free(line_orig);
		// free(data->command);
	}
}
