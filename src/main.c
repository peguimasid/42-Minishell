/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucafern <lucafern@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 17:31:19 by gmasid            #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/10/29 17:22:06 by lucafern         ###   ########.fr       */
=======
/*   Updated: 2022/11/05 21:16:23 by gmasid           ###   ########.fr       */
>>>>>>> 94d5e82586533380ec0faa173c0bd303ef15f2b8
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	main(int argc, char **argv, char **envp)
{
	if (argc != 1)
		return (throw_error(0, 1, "No arguments in this program"));
	return (minishell(argv, envp));
}
