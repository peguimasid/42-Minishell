/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucafern <lucasfads@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 11:19:09 by lucafern          #+#    #+#             */
/*   Updated: 2022/05/15 11:19:09 by lucafern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	new_nb;
	char			digit;

	if (n < 0)
	{
		write(fd, "-", 1);
		new_nb = n * -1;
	}
	else
		new_nb = n;
	if (new_nb >= 10)
		ft_putnbr_fd(new_nb / 10, fd);
	digit = new_nb % 10 + '0';
	write (fd, &digit, 1);
}
