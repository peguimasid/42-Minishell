/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_types.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucafern <lucafern@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 19:50:05 by lucafern          #+#    #+#             */
/*   Updated: 2022/08/08 10:22:51 by lucafern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	print_s(va_list argptr)
{
	char	*str;
	int		len;

	len = 0;
	str = va_arg(argptr, char *);
	if (str)
	{
		ft_putstr_fd(str, 1);
		len += ft_strlen(str);
	}
	else
	{
		ft_putstr_fd("(null)", 1);
		len += 6;
	}
	return (len);
}

int	print_i_d(va_list argptr)
{
	char	*str;
	int		len;

	len = 0;
	str = ft_itoa(va_arg(argptr, int));
	ft_putstr_fd(str, 1);
	len += ft_strlen(str);
	free(str);
	return (len);
}

int	print_u(va_list argptr)
{
	char	*str;
	int		len;

	len = 0;
	str = ft_utoa(va_arg(argptr, unsigned int));
	ft_putstr_fd(str, 1);
	len += ft_strlen(str);
	free(str);
	return (len);
}

int	print_x(va_list argptr, char type)
{
	char	*str;
	int		len;

	len = 0;
	str = ft_itoh(va_arg(argptr, int), type);
	ft_putstr_fd(str, 1);
	len += ft_strlen(str);
	free(str);
	return (len);
}

int	print_p(va_list argptr)
{
	char	*str;
	int		len;

	len = 0;
	str = ft_ptoul(va_arg(argptr, unsigned long));
	ft_putstr_fd("0x", 1);
	ft_putstr_fd(str, 1);
	len += ft_strlen(str) + 2;
	free(str);
	return (len);
}
