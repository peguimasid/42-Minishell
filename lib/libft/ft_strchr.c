/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucafern <lucasfads@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 17:43:46 by lucafern          #+#    #+#             */
/*   Updated: 2022/05/07 17:43:46 by lucafern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strchr(const char *s, int c)
{
	char			*p;
	unsigned char	ch;

	p = (char *)s;
	ch = c;
	while (*p != ch)
	{
		if (*p == '\0')
			return (NULL);
		p++;
	}
	return (p);
}
