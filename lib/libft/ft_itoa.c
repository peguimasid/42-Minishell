/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucafern <lucasfads@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 16:16:15 by lucafern          #+#    #+#             */
/*   Updated: 2022/05/14 16:16:15 by lucafern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	measure_to_str(int n)
{
	size_t		char_len;
	long int	temp;

	char_len = 1;
	temp = n;
	if (n < 0)
	{
		temp *= -1;
		char_len++;
	}
	while (temp >= 10)
	{
		temp /= 10;
		char_len++;
	}
	return (char_len);
}

char	*ft_itoa(int n)
{
	size_t		char_len;
	char		*str;
	long int	temp;
	int			i;

	char_len = measure_to_str(n);
	str = malloc(char_len + 1);
	if (!str)
		return (NULL);
	i = 1;
	temp = n;
	if (n < 0)
		temp *= -1;
	while ((int)char_len - i >= 0)
	{
		str[char_len - i] = temp % 10 + '0';
		temp /= 10;
		i++;
	}
	if (n < 0)
		str[0] = '-';
	str[char_len] = '\0';
	return (str);
}
