/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_push.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 12:41:50 by gmasid            #+#    #+#             */
/*   Updated: 2022/11/06 12:51:35 by gmasid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

char	**matrix_push(char **matrix, char *new)
{
	char	**result;
	int		i;
	int		len;

	i = 0;
	if (!new)
		return (matrix);
	len = matrix_len(matrix);
	result = malloc(sizeof(char *) * (len + 2));
	result[len + 1] = NULL;
	if (!result)
		return (matrix);
	while (i < len)
	{
		result[i] = ft_strdup(matrix[i]);
		if (!result[i])
		{
			free_matrix(matrix);
			free_matrix(result);
		}
		i++;
	}
	result[i] = ft_strdup(new);
	free_matrix(matrix);
	return (result);
}
