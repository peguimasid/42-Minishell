/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoh.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucafern <lucasfads@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 13:10:08 by lucafern          #+#    #+#             */
/*   Updated: 2022/06/25 13:10:08 by lucafern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	measure_h_to_str(unsigned int n)
{
	size_t		char_len;
	long int	temp;

	char_len = 1;
	temp = n;
	while (temp >= 16)
	{
		temp /= 16;
		char_len++;
	}
	return (char_len);
}

char	*ft_itoh(unsigned int n, char type)
{
	size_t		char_len;
	char		*str;
	long int	temp;
	int			i;
	char		*base;

	base = NULL;
	if (type == 'X')
		base = "0123456789ABCDEF";
	else if (type == 'x')
		base = "0123456789abcdef";
	char_len = measure_h_to_str(n);
	str = malloc(char_len + 1);
	if (!str)
		return (NULL);
	i = 1;
	temp = n;
	while ((int)char_len - i >= 0)
	{
		str[char_len - i] = base[temp % 16];
		temp /= 16;
		i++;
	}
	str[char_len] = '\0';
	return (str);
}
