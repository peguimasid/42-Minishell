/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucafern <lucasfads@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 13:54:22 by lucafern          #+#    #+#             */
/*   Updated: 2022/06/25 13:54:22 by lucafern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	measure_u_to_str(unsigned int n)
{
	size_t		char_len;
	long int	temp;

	char_len = 1;
	temp = n;
	while (temp >= 10)
	{
		temp /= 10;
		char_len++;
	}
	return (char_len);
}

char	*ft_utoa(unsigned int n)
{
	size_t		char_len;
	char		*str;
	long int	temp;
	int			i;

	char_len = measure_u_to_str(n);
	str = malloc(char_len + 1);
	if (!str)
		return (NULL);
	i = 1;
	temp = n;
	while ((int)char_len - i >= 0)
	{
		str[char_len - i] = temp % 10 + '0';
		temp /= 10;
		i++;
	}
	str[char_len] = '\0';
	return (str);
}
