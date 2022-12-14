/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucafern <lucafern@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
<<<<<<< HEAD:src/exec/handle_prompt.c
/*   Created: 2022/10/25 19:34:08 by gmasid            #+#    #+#             */
/*   Updated: 2022/10/29 19:28:39 by lucafern         ###   ########.fr       */
=======
/*   Created: 2022/12/03 17:37:28 by gmasid            #+#    #+#             */
/*   Updated: 2022/12/03 17:37:46 by gmasid           ###   ########.fr       */
>>>>>>> 94d5e82586533380ec0faa173c0bd303ef15f2b8:src/utils/tools/ft_strcat.c
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

char	*ft_strcat(char *src, char *dest)
{
	int		i;
	int		y;
	int		len;
	char	*result;

	i = 0;
	y = 0;
	len = (ft_strlen(src) + ft_strlen(dest));
	result = malloc(sizeof(char) * len + 1);
	while (src[i] != '\0')
	{
<<<<<<< HEAD:src/exec/handle_prompt.c
		data->running = false;
		free_env(data);
		rl_clear_history();
		free_args(args);
		return ;
=======
		result[i] = src[i];
		i++;
>>>>>>> 94d5e82586533380ec0faa173c0bd303ef15f2b8:src/utils/tools/ft_strcat.c
	}
	while (dest[y] != '\0')
	{
<<<<<<< HEAD:src/exec/handle_prompt.c
		execute_builtin(data, args, envp);
		free_args(args);
		return ;
	}
	execute_bin(data, args, envp);
	free_args(args);
=======
		result[i] = dest[y];
		i++;
		y++;
	}
	result[i] = '\0';
	return (result);
>>>>>>> 94d5e82586533380ec0faa173c0bd303ef15f2b8:src/utils/tools/ft_strcat.c
}
