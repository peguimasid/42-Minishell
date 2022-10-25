/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucafern <lucasfads@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 18:08:19 by lucafern          #+#    #+#             */
/*   Updated: 2022/05/07 18:08:19 by lucafern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strrchr(const char *s, int c)
{
	char			*p;
	unsigned char	ch;

	p = (char *)s + ft_strlen((char *)s);
	ch = c;
	while (*p != ch)
	{
		if (p == s)
			return (NULL);
		p--;
	}
	return (p);
}
