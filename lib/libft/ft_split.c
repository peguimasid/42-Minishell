/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucafern <lucasfads@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 13:08:06 by lucafern          #+#    #+#             */
/*   Updated: 2022/05/12 13:08:06 by lucafern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strchr(const char *s, int c);

static int	count_strings(char const *s, char c)
{
	int	array_n;
	int	i;

	array_n = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if ((s[i] != c && (i == 0 || s[i - 1] == c)))
			array_n++;
		i++;
	}
	return (array_n);
}

static char	**no_split(char const *s, char **array)
{
	array[0] = ft_substr(s, 0, ft_strlen((char *)s));
	return (array);
}

static char	**multi_split(char const *s, char **array, char c)
{
	int		pos;
	size_t	str_len;

	pos = 0;
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s)
		{
			str_len = 0;
			while (s[str_len] != c && s[str_len] != '\0')
				str_len++;
			array[pos++] = ft_substr(s, 0, str_len);
			s += str_len;
		}
	}
	return (array);
}

char	**ft_split(char const *s, char c)
{
	int		array_n;
	char	**array;

	if (!s)
		return (NULL);
	array_n = count_strings((char *)s, c);
	array = (char **)malloc(sizeof(char *) * (array_n + 1));
	if (!array)
		return (NULL);
	array[array_n] = NULL;
	if (array_n == 0)
		return (array);
	if (!c)
		return (no_split(s, array));
	return (multi_split(s, array, c));
}
