/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   restrict_atoi.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 18:42:07 by gmasid            #+#    #+#             */
/*   Updated: 2022/12/06 14:24:36 by gmasid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

static int	is_space(char c)
{
	return (c == '\t' || c == '\n' || c == '\r' || c == '\v' || c == '\f'
		|| c == ' ');
}

int	restrict_atoi(const char *str)
{
	int		sign;
	long	result;
	size_t	i;

	result = 0;
	sign = 1;
	i = 0;
	while (str[i] != '\0' && is_space(str[i]))
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (!ft_isdigit(str[i]))
		return (-1);
	while (str[i] != '\0' && ft_isdigit(str[i]))
	{
		result = (str[i] - '0') + (result * 10);
		i++;
	}
	if (str[i] && !is_space(str[i]))
		return (-1);
	return (result * sign);
}
