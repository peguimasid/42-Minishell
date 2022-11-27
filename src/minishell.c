/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucafern <lucafern@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 08:50:30 by gmasid            #+#    #+#             */
/*   Updated: 2022/11/27 12:41:25 by lucafern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	launch(t_data *data, char **env)
{
	char	*line_orig;
	t_list	*single_pipes;
	t_list	*current_pipe;
	int		i;

	(void)env;
	while (data->running)
	{
		i = 0;
		single_pipes = NULL;
		line_orig = readline("Minishell ⇢ ");
		single_pipes = pipe_separator(line_orig);
		// ft_print_lst(single_pipes);
		current_pipe = single_pipes;
		while (i < ft_lstsize(single_pipes))
		{
			data->command = current_pipe->content;
			// printf("o comando %i é: %s\n", i, (char *)current_pipe->content);
			if (current_pipe->content)
				handle_prompt(data, env);
			current_pipe = single_pipes->next;
			i++;
		}
		// ft_print_lst(single_pipes);
		free(line_orig);
		// free(data->command);
	}
}
