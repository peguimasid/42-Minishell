/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucafern <lucafern@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 13:13:04 by lucafern          #+#    #+#             */
/*   Updated: 2022/08/08 10:22:25 by lucafern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	print_type(va_list argptr, char type)
{
	int		len;

	len = 0;
	if (type == 'c')
		ft_putchar_fd(va_arg(argptr, int), 1);
	else if (type == 's')
		len += print_s(argptr);
	else if (type == 'd' || type == 'i')
		len += print_i_d(argptr);
	else if (type == 'x' || type == 'X')
		len += print_x(argptr, type);
	else if (type == 'u')
		len += print_u(argptr);
	else if (type == 'p')
		len += print_p(argptr);
	else if (type == '%')
		ft_putchar_fd('%', 1);
	if (type == 'c' || type == '%')
		len++;
	return (len);
}
