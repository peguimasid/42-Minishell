/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 19:52:34 by gmasid            #+#    #+#             */
/*   Updated: 2022/10/25 20:04:18 by gmasid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	change_directory(char **args, char **env)
{
	(void)args;
	(void)env;
	printf("OK\n");
	return (1);
}

int	execute_builtin(char **args, char **envp)
{
	if (ft_strcmp(args[0], "cd") == 0)
		return (change_directory(args, envp));
	return (0);
}
