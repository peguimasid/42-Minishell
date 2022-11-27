/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_old.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucafern <lucafern@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 17:06:05 by lucafern          #+#    #+#             */
/*   Updated: 2022/11/27 11:40:49 by lucafern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	prompt(void)
{
	char	*line_orig;
	t_list	*single_pipes;

	while (1)
	{
		single_pipes = NULL;
		line_orig = readline("Minishell ⇢ ");
		single_pipes = pipe_separator(line_orig);
		ft_print_lst(single_pipes);
		free(line_orig);
	}
}

int	main(void)
{
	prompt();
}
