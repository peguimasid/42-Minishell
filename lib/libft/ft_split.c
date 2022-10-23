/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 14:28:20 by gmasid            #+#    #+#             */
/*   Updated: 2022/05/22 15:00:13 by gmasid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(const char *str, char c);
static char	*dup_word(const char *str, int start, int finish);
static void	free_result(char **result, size_t j);
static char	**fill_result(char **result, const char *s, char c);

char	**ft_split(char const *s, char c)
{
	char	**result;

	if (!s)
		return (0);
	result = malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!result)
		return (0);
	result = fill_result(result, s, c);
	return (result);
}

static int	count_words(const char *str, char c)
{
	int	i;
	int	trigger;

	i = 0;
	trigger = 0;
	while (*str)
	{
		if (*str != c && trigger == 0)
		{
			trigger = 1;
			i++;
		}
		else if (*str == c)
			trigger = 0;
		str++;
	}
	return (i);
}

static char	*dup_word(const char *str, int start, int finish)
{
	char	*word;
	int		i;

	i = 0;
	word = malloc((finish - start + 1) * sizeof(char));
	while (start < finish)
		word[i++] = str[start++];
	word[i] = 0;
	return (word);
}

static void	free_result(char **result, size_t j)
{
	while (j--)
	{
		free(result[j]);
	}
	free(result);
}

static char	**fill_result(char **result, const char *s, char c)
{
	size_t	i;
	size_t	j;
	int		dup_start_index;

	i = 0;
	j = 0;
	dup_start_index = -1;
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && dup_start_index < 0)
			dup_start_index = i;
		else if ((s[i] == c || i == ft_strlen(s)) && dup_start_index >= 0)
		{
			result[j] = dup_word(s, dup_start_index, i);
			if (!result[j++])
			{
				free_result(result, j);
				return (NULL);
			}
			dup_start_index = -1;
		}
		i++;
	}
	result[j] = 0;
	return (result);
}
