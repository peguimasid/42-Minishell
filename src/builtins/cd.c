/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucafern <lucafern@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 15:45:54 by lucafern          #+#    #+#             */
/*   Updated: 2022/10/25 17:13:58 by lucafern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	cd(char **command)
{
	if (!command[1])
		printf("Error: CD needs a path\n");
	else if (!command[2])
	{
		if (chdir(command[1]))
			perror("Error");
	}
	else
		printf("Error: Too many arguments\n");
}
