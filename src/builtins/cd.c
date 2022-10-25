/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucafern <lucafern@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 15:45:54 by lucafern          #+#    #+#             */
/*   Updated: 2022/10/25 16:56:52 by lucafern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	cd(char **command)
{
	if (!command[1])
		printf("Error: CD needs a path\n");
	else if (!command[2])
		chdir(command[1]);
	else
		printf("Error: Too many arguments\n");
}
