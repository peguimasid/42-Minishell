/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_replace.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 12:41:50 by gmasid            #+#    #+#             */
/*   Updated: 2022/11/07 18:22:57 by gmasid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

char	**matrix_replace(char **matrix, int i, char *new_value)
{
	if (!matrix || !matrix[i])
		return (NULL);
	free(matrix[i]);
	matrix[i] = ft_strdup(new_value);
	return (matrix);
}
