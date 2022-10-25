/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucafern <lucasfads@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 11:41:09 by lucafern          #+#    #+#             */
/*   Updated: 2022/05/05 11:41:09 by lucafern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	char	*s1_i;
	char	*s2_i;

	s1_i = (char *)s1;
	s2_i = (char *)s2;
	while (*s1_i != '\0' && *s2_i != '\0' && n > 0)
	{
		if (*s1_i != *s2_i || *s1_i == '\0' || *s2_i == '\0')
			break ;
		s1_i++;
		s2_i++;
		n--;
	}
	if (n == 0)
		return (0);
	return (*(unsigned char *)s1_i - *(unsigned char *)s2_i);
}
