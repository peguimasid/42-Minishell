/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucafern <lucafern@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 21:16:11 by gmasid            #+#    #+#             */
/*   Updated: 2022/10/29 20:14:18 by lucafern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*result;

	len = ft_strlen(s1) + 1;
	result = malloc(sizeof(char) * len);
	if (!result)
		return (NULL);
	result = ft_memcpy(result, s1, len);
	return (result);
}
