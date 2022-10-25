/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucafern <lucasfads@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 19:11:41 by lucafern          #+#    #+#             */
/*   Updated: 2022/05/10 19:11:41 by lucafern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	len_s;
	size_t	len_sub;
	char	*s_p;
	char	*substr;

	if (!s)
		return (NULL);
	len_s = ft_strlen((char *)s);
	if (start > len_s)
		return (ft_strdup(""));
	len_sub = len_s - start;
	if (start + len > len_s)
		len = len_sub;
	len++;
	s_p = (char *)s;
	s_p += start;
	substr = malloc(len);
	if (!substr)
		return (NULL);
	ft_strlcpy(substr, s_p, len);
	return (substr);
}
