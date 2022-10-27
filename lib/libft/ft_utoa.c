/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 13:44:56 by gmasid            #+#    #+#             */
/*   Updated: 2022/06/08 20:50:06 by gmasid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_len(unsigned int n)
{
	size_t	result;

	result = 0;
	while (n)
	{
		result++;
		n /= 10;
	}
	return (result);
}

static char	*generate(char *result, long n, int len)
{
	if (n == 0)
		return (result = ft_strdup("0"));
	result[len] = '\0';
	while (len)
	{
		result[len - 1] = (n % 10) + '0';
		n /= 10;
		len--;
	}
	return (result);
}

char	*ft_utoa(unsigned int n)
{
	int		len;
	char	*result;

	len = get_len(n);
	result = malloc(sizeof(char) * (len + 1));
	if (!result)
		return (0);
	result = generate(result, n, len);
	if (!result)
		return (0);
	return (result);
}
