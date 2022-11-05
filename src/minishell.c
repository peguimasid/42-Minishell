/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucafern <lucafern@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 17:06:05 by lucafern          #+#    #+#             */
/*   Updated: 2022/11/05 18:53:58 by lucafern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	prompt(void)
{
	char	*line_orig;
	t_list	*tokens;

	while (1)
	{
		tokens = NULL;
		line_orig = readline("Minishell ⇢ ");
		tokens = lexer(line_orig);
		ft_print_lst(tokens);
		free(line_orig);
	}
}

int	main(void)
{
	prompt();
}
