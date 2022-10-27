/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucafern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 10:47:07 by lucafern          #+#    #+#             */
/*   Updated: 2022/06/17 10:50:49 by lucafern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf(const char *str, ...)
{
	va_list	argptr;
	int		i;
	int		len;
	char	c;

	i = 0;
	len = 0;
	va_start(argptr, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			len += print_type(argptr, str[i + 1]);
			i++;
		}
		else
		{
			c = str[i];
			write (1, &c, 1);
			len++;
		}
		i++;
	}
	va_end(argptr);
	return (len);
}
