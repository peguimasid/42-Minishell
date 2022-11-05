/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucafern <lucafern@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 17:06:05 by lucafern          #+#    #+#             */
/*   Updated: 2022/11/05 17:56:04 by lucafern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	prompt(void)
{
	char	*line_orig;
	char	**tokens;
	t_list	*token_list;

	while (1)
	{
		line_orig = readline("Minishell ⇢ ");
		tokens = lexer(line_orig);
		token_list = init_lst(tokens);
		ft_print_lst(token_list);
		free(line_orig);
	}
}

int	main(void)
{
	prompt();
}
