/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucafern <lucasfads@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 21:48:55 by lucafern          #+#    #+#             */
/*   Updated: 2022/06/16 21:48:55 by lucafern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*read_file(int bytes, char *temp, char *buffer, int fd)
{
	char	*aux;
	char	*aux2;

	aux = ft_strjoin(temp, "");
	free(temp);
	temp = NULL;
	while (bytes > 0)
	{
		aux2 = ft_strjoin(aux, buffer);
		free(aux);
		aux = NULL;
		aux = ft_strjoin(aux2, "");
		free(aux2);
		aux2 = NULL;
		if (ft_strchr(aux, '\n'))
			break ;
		bytes = read(fd, buffer, BUFFER_SIZE);
		buffer[bytes] = '\0';
	}
	free(buffer);
	buffer = NULL;
	return (aux);
}

char	*build_line(char *temp, const size_t i)
{
	char	*new_line;

	if (temp[i] == '\n')
	{
		new_line = (char *)malloc(i + 2);
		ft_memcpy(new_line, temp, i + 1);
		new_line[i] = '\n';
		new_line[i + 1] = '\0';
	}
	else
	{
		new_line = (char *)malloc(i + 1);
		ft_memcpy(new_line, temp, i);
		new_line[i] = '\0';
	}
	return (new_line);
}

char	*next_temp(char *temp, size_t i)
{
	char	*move_temp;
	char	*new_temp;

	move_temp = ft_strjoin(temp, "");
	new_temp = ft_strjoin(temp, "");
	if (temp[i] == '\n')
		i++;
	free(new_temp);
	new_temp = NULL;
	move_temp += i;
	if (*move_temp)
		new_temp = ft_strjoin(move_temp, "");
	move_temp -= i;
	free(move_temp);
	free (temp);
	return (new_temp);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	int			bytes;
	static char	*temp[4096];
	size_t		i;
	char		*line;

	if (!temp[fd])
		temp[fd] = ft_strjoin("", "");
	buffer = (char *)malloc(BUFFER_SIZE + 1);
	bytes = read(fd, buffer, BUFFER_SIZE);
	if (fd < 0 || !buffer || (bytes <= 0 && !ft_strlen(temp[fd])))
	{
		free (temp[fd]);
		temp[fd] = NULL;
		free(buffer);
		return (NULL);
	}
	buffer[bytes] = '\0';
	temp[fd] = read_file(bytes, temp[fd], buffer, fd);
	i = 0;
	while (temp[fd][i] != '\n' && temp[fd][i])
		i++;
	line = build_line(temp[fd], i);
	temp[fd] = next_temp(temp[fd], i);
	return (line);
}
