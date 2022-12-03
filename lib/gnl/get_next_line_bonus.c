/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 15:13:17 by gmasid            #+#    #+#             */
/*   Updated: 2022/12/03 15:27:48 by gmasid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*read_file_until_find_next_line(int fd, char *work_str)
{
	int		read_bytes_amount;
	char	*buff;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	read_bytes_amount = 1;
	while (!gnl_strchr(work_str, '\n') && read_bytes_amount != 0)
	{
		read_bytes_amount = read(fd, buff, BUFFER_SIZE);
		if (read_bytes_amount == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[read_bytes_amount] = '\0';
		work_str = gnl_strjoin(work_str, buff);
	}
	free(buff);
	return (work_str);
}

char	*get_next_line(int fd)
{
	char		*result;
	static char	*work_strs[4096];

	if (BUFFER_SIZE < 1 || fd < 0)
		return (NULL);
	work_strs[fd] = read_file_until_find_next_line(fd, work_strs[fd]);
	if (!work_strs[fd])
		return (NULL);
	result = get_part_before_next_line_from_work_string(work_strs[fd]);
	work_strs[fd] = get_part_after_next_line_from_work_string(work_strs[fd]);
	return (result);
}
