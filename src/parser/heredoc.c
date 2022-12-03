/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 14:22:59 by gmasid            #+#    #+#             */
/*   Updated: 2022/12/02 23:33:16 by gmasid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	input_is_delimiter_or_user_quit(char *input, char *delimiter)
{
	int		is_delimiter;
	int		input_len_eq_delimiter_len;
	size_t	input_len;

	if (!input)
		return (0);
	input_len = ft_strlen(input) - 1;
	is_delimiter = (ft_strncmp(input, delimiter, ft_strlen(delimiter)) == 0);
	input_len_eq_delimiter_len = (input_len == ft_strlen(delimiter));
	if (is_delimiter && input_len_eq_delimiter_len)
		return (1);
	if (g_status == 130)
		return (1);
	return (0);
}

char	*get_string(char *delimiter)
{
	char	*result;
	char	*input;
	char	*tmp;

	result = NULL;
	input = NULL;
	while (!input_is_delimiter_or_user_quit(input, delimiter))
	{
		tmp = result;
		result = ft_strjoin(result, input);
		free(tmp);
		free(input);
		input = readline("▸ ");
		if (!input)
		{
			printf("%s (wanted `%s\')\n", HDOC_WARN, delimiter);
			break ;
		}
		tmp = input;
		input = ft_strjoin(input, "\n");
		free(tmp);
	}
	free(input);
	return (result);
}

int	get_heredoc(char *delimiter)
{
	int		fd[2];
	char	*input_str;

	input_str = NULL;
	g_status = 0;
	if (pipe(fd) == -1)
	{
		throw_error(PIPERR, 1, NULL);
		return (-1);
	}
	input_str = get_string(delimiter);
	write(fd[WRITE_END], input_str, ft_strlen(input_str));
	free(input_str);
	close(fd[WRITE_END]);
	if (g_status == 130)
	{
		close(fd[READ_END]);
		return (-1);
	}
	return (fd[READ_END]);
}
