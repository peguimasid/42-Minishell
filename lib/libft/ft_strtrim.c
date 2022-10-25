/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucafern <lucasfads@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 10:03:22 by lucafern          #+#    #+#             */
/*   Updated: 2022/05/12 10:03:22 by lucafern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c);
char	*ft_substr(char const *s, unsigned int start, size_t len);

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	trimmed_n;
	char	*trimmed;

	if (!s1 || !set)
		return (NULL);
	while (*s1)
	{
		if (ft_strchr(set, *s1))
			s1++;
		else
			break ;
	}
	trimmed_n = ft_strlen((char *)s1);
	while (ft_strchr(set, s1[trimmed_n]))
		trimmed_n--;
	trimmed = ft_substr((char *)s1, 0, trimmed_n + 1);
	return (trimmed);
}
