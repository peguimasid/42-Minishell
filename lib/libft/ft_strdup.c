/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucafern <lucasfads@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 17:04:48 by lucafern          #+#    #+#             */
/*   Updated: 2022/05/10 17:04:48 by lucafern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	len;
	char	*str;

	len = ft_strlen((char *)s) + 1;
	str = malloc(len);
	if (str == NULL)
		return (str);
	ft_strlcpy(str, s, len);
	return (str);
}
