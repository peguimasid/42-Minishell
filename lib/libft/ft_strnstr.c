/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucafern <lucasfads@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 19:19:20 by lucafern          #+#    #+#             */
/*   Updated: 2022/05/07 19:19:20 by lucafern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n);

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	s2_n;

	if (*s2 == '\0')
		return ((char *)s1);
	s2_n = ft_strlen((char *)s2);
	while (*s1 && n-- >= s2_n)
	{
		if (*s1 == s2[0] && ft_strncmp((char *)s1, (char *)s2, s2_n) == 0)
			return ((char *)s1);
		s1++;
	}
	return (NULL);
}
