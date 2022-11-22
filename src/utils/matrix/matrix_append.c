/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_append.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 16:45:46 by gmasid            #+#    #+#             */
/*   Updated: 2022/11/22 17:56:46 by gmasid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

char	**matrix_append(char **dest, char **src, int start_index)
{
	char	**result;
	int		i;
	int		j;
	int		k;

	i = -1;
	j = -1;
	k = -1;
	printf("%d [] %d\n", matrix_len(dest), start_index);
	if (!dest || start_index < 0 || start_index >= matrix_len(dest))
		return (dest);
	result = ft_calloc(matrix_len(dest) + matrix_len(src), sizeof(char *));
	while (result && dest[++i])
	{
		if (i == start_index)
			while (src && src[++j])
				result[++k] = ft_strdup(src[j]);
		else
			result[++k] = ft_strdup(dest[i]);
	}
	free_matrix(dest);
	return (result);
}
