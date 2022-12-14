/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_dup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucafern <lucafern@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
<<<<<<< HEAD:src/env/init.c
/*   Created: 2022/10/29 09:08:14 by gmasid            #+#    #+#             */
/*   Updated: 2022/10/29 19:44:16 by lucafern         ###   ########.fr       */
=======
/*   Created: 2022/11/05 13:46:02 by gmasid            #+#    #+#             */
/*   Updated: 2022/12/10 15:50:14 by gmasid           ###   ########.fr       */
>>>>>>> 94d5e82586533380ec0faa173c0bd303ef15f2b8:src/utils/matrix/matrix_dup.c
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

char	**dup_matrix(char **matrix)
{
	char	**result;
	int		i;
<<<<<<< HEAD:src/env/init.c
	char	*key;
	char	*value;
=======
>>>>>>> 94d5e82586533380ec0faa173c0bd303ef15f2b8:src/utils/matrix/matrix_dup.c

	i = 0;
	result = malloc(sizeof(char *) * (matrix_len(matrix) + 1));
	if (!result)
		return (NULL);
	while (matrix && matrix[i])
	{
<<<<<<< HEAD:src/env/init.c
		key = ft_substr(env[i], 0, str_ichr(env[i], '='));
		value = ft_substr(env[i], str_ichr(env[i], '=') + 1, ft_strlen(env[i]));
		set_env(data, key, value);
=======
		result[i] = ft_strdup(matrix[i]);
		if (!result[i])
		{
			free_matrix(result);
			return (NULL);
		}
>>>>>>> 94d5e82586533380ec0faa173c0bd303ef15f2b8:src/utils/matrix/matrix_dup.c
		i++;
	}
	result[i] = NULL;
	return (result);
}
