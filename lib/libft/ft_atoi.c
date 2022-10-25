/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucafern <lucasfads@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 11:47:46 by lucafern          #+#    #+#             */
/*   Updated: 2022/05/05 11:47:46 by lucafern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	return_overflow(int minus_count)
{
	if (minus_count == 0)
		return (-1);
	return (0);
}

int	ft_atoi(char *str)
{
	int		count;
	int		minus_count;
	long	num;
	long	long_num;

	count = 0;
	minus_count = 0;
	num = 0;
	while (str[count] == ' ' || (str[count] >= 9 && str[count] <= 15))
		count++;
	if (str[count] == '-' || str[count] == '+')
	{
		if (str[count++] == '-')
			minus_count++;
	}
	while (str[count] >= '0' && str[count] <= '9')
	{
		long_num = num;
		num = (num * 10) + (str[count++] - 48);
		if (long_num > num)
			return (return_overflow(minus_count));
	}
	if (minus_count % 2 == 1)
		num *= -1;
	return (num);
}
