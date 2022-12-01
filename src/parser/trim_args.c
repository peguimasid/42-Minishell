/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trim_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 16:57:37 by gmasid            #+#    #+#             */
/*   Updated: 2022/12/01 17:09:16 by gmasid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	should_remove(char *str, int sq_open, int dq_open, int i)
{
	if (str[i] == DOUBLE_QUOTE && !sq_open)
		return (1);
	if (str[i] == SINGLE_QUOTE && !dq_open)
		return (1);
	return (0);
}

static int	count_items_to_remove(char *str)
{
	int	result;
	int	dq_open;
	int	sq_open;
	int	i;

	i = 0;
	result = 0;
	dq_open = 0;
	sq_open = 0;
	while (str && str[i])
	{
		sq_open = (sq_open + (!dq_open && str[i] == SINGLE_QUOTE)) % 2;
		dq_open = (dq_open + (!sq_open && str[i] == DOUBLE_QUOTE)) % 2;
		if (should_remove(str, sq_open, dq_open, i))
			result++;
		i++;
	}
	return (result);
}

char	*trim_arg(char *str, int sq_open, int dq_open)
{
	char	*result;
	int		to_remove;
	int		i;
	int		j;

	j = 0;
	i = 0;
	to_remove = count_items_to_remove(str);
	result = malloc(sizeof(char) * (ft_strlen(str) - to_remove + 1));
	while (str[i])
	{
		sq_open = (sq_open + (!dq_open && str[i] == SINGLE_QUOTE)) % 2;
		dq_open = (dq_open + (!sq_open && str[i] == DOUBLE_QUOTE)) % 2;
		if (!should_remove(str, sq_open, dq_open, i))
			result[j++] = str[i];
		i++;
	}
	result[j] = '\0';
	return (result);
}

char	**trim_args(char **args)
{
	char	**result;
	char	*arg_trimmed;
	int		i;

	i = 0;
	result = dup_matrix(args);
	while (result && result[i])
	{
		arg_trimmed = trim_arg(result[i], 0, 0);
		free(result[i]);
		result[i] = arg_trimmed;
		i++;
	}
	return (result);
}
