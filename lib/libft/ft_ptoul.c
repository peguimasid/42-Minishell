/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptoul.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucafern <lucasfads@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 14:36:06 by lucafern          #+#    #+#             */
/*   Updated: 2022/06/25 14:36:06 by lucafern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	measure_p_to_str(unsigned long n)
{
	size_t			char_len;
	unsigned long	temp;

	char_len = 1;
	temp = n;
	while (temp >= 16)
	{
		temp /= 16;
		char_len++;
	}
	return (char_len);
}

char	*ft_ptoul(unsigned long n)
{
	size_t			char_len;
	char			*str;
	unsigned long	temp;
	int				i;
	char			*base;

	base = "0123456789abcdef";
	char_len = measure_p_to_str(n);
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
