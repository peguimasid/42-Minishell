/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 17:31:19 by gmasid            #+#    #+#             */
/*   Updated: 2022/10/23 13:17:19 by gmasid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	main(int argc, char **argv, char **env)
{
	char	*line;

	(void)argc;
	(void)argv;
	printf("%s\n", *env);
	printf("%d\n", ft_atoi("41") + 1);
	while (1)
	{
		line = readline("Minishell ▸ ");
		printf("command was: %s\n", line);
		execve("/bin/ls", ft_split(line, ' '), env);
	}
}
