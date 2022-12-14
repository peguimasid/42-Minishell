/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 15:48:04 by gmasid            #+#    #+#             */
/*   Updated: 2022/11/26 14:19:37 by gmasid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

int	is_empty(char *input)
{
	return (input && ft_strlen(input) == 0);
}

int	is_null(char *input)
{
	return (input == NULL);
}

int	get_invalid_input_status(char *input)
{
	if (is_null(input))
		return (0);
	return (1);
}

int	is_invalid_input(char *input)
{
	return (is_empty(input) || is_null(input));
}
