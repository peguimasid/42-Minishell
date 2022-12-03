/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 11:06:30 by gmasid            #+#    #+#             */
/*   Updated: 2022/12/03 15:27:33 by gmasid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	gnl_strlen(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*gnl_strchr(char *s, int c)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
	{
		if (s[i] == (unsigned char)c)
			return (s + i);
		i++;
	}
	if (c == '\0')
		return (s + i);
	return (0);
}

char	*gnl_strjoin(char *work_str, char *buff)
{
	char	*result;
	size_t	i;
	size_t	j;

	if (!work_str)
	{
		work_str = malloc(1 * sizeof(char));
		work_str[0] = '\0';
	}
	if (!work_str || !buff)
		return (NULL);
	result = malloc(sizeof(char) * (gnl_strlen(work_str) + gnl_strlen(buff)
				+ 1));
	if (!result)
		return (NULL);
	i = -1;
	if (work_str)
		while (work_str[++i])
			result[i] = work_str[i];
	j = 0;
	while (buff[j])
		result[i++] = buff[j++];
	result[gnl_strlen(work_str) + gnl_strlen(buff)] = '\0';
	free(work_str);
	return (result);
}

char	*get_part_before_next_line_from_work_string(char *work_str)
{
	size_t	i;
	char	*result;

	i = 0;
	if (!work_str[i])
		return (NULL);
	while (work_str[i] && work_str[i] != '\n')
		i++;
	result = malloc(sizeof(char) * (i + 2));
	if (!result)
		return (NULL);
	i = 0;
	while (work_str[i] && work_str[i] != '\n')
	{
		result[i] = work_str[i];
		i++;
	}
	if (work_str[i] == '\n')
	{
		result[i] = work_str[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

char	*get_part_after_next_line_from_work_string(char *work_str)
{
	size_t	i;
	size_t	j;
	char	*result;

	i = 0;
	while (work_str[i] && work_str[i] != '\n')
		i++;
	if (!work_str[i])
	{
		free(work_str);
		return (NULL);
	}
	result = malloc(sizeof(char) * (gnl_strlen(work_str) - i + 1));
	if (!result)
		return (NULL);
	j = 0;
	i++;
	while (work_str[i])
		result[j++] = work_str[i++];
	result[j] = '\0';
	free(work_str);
	return (result);
}
