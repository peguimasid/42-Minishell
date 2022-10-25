/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucafern <lucasfads@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 11:30:33 by lucafern          #+#    #+#             */
/*   Updated: 2022/05/05 11:30:33 by lucafern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i_count;
	size_t	i_pos;
	char	*src_i;

	i_count = 0;
	src_i = (char *)src;
	while (src_i[i_count] != '\0')
		i_count++;
	if (size != 0)
	{
		i_pos = 0;
		while (src_i[i_pos] != '\0' && i_pos < size - 1)
		{
			dest[i_pos] = src_i[i_pos];
			i_pos++;
		}
		dest[i_pos] = '\0';
	}
	return (i_count);
}
