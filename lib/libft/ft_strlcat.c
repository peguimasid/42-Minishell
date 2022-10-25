/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucafern <lucasfads@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 11:34:21 by lucafern          #+#    #+#             */
/*   Updated: 2022/05/05 11:34:21 by lucafern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	dest_count;
	size_t	src_count;
	size_t	dest_pos;
	size_t	src_pos;
	char	*src_i;

	dest_count = 0;
	src_count = 0;
	src_i = (char *)src;
	while (dest[dest_count] != '\0')
		dest_count++;
	while (src_i[src_count] != '\0')
		src_count++;
	if (size == 0)
		return (src_count);
	if (size <= dest_count)
		return (src_count += size);
	else
		src_count += dest_count;
	dest_pos = dest_count;
	src_pos = 0;
	while (src_i[src_pos] && dest_pos < size - 1)
		dest[dest_pos++] = src_i[src_pos++];
	dest[dest_pos] = '\0';
	return (src_count);
}
