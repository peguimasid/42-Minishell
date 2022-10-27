/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 13:50:20 by gmasid            #+#    #+#             */
/*   Updated: 2022/05/17 12:07:52 by gmasid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*dest_tmp;
	const char	*src_tmp;

	if (dst == src || n == 0)
		return (dst);
	if (!dst && !src)
		return (0);
	dest_tmp = (char *)dst;
	src_tmp = (const char *)src;
	while (n--)
		dest_tmp[n] = src_tmp[n];
	return (dst);
}
