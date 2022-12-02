/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 14:22:59 by gmasid            #+#    #+#             */
/*   Updated: 2022/12/02 15:25:25 by gmasid           ###   ########.fr       */
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

	result = NULL;
	input = NULL;
	while (!input_is_delimiter_or_user_quit(input, delimiter))
	{
		result = ft_strjoin(result, input);
		input = readline("▸ ");
		if (!input)
		{
			printf("%s (wanted `%s\')\n", HDOC_WARN, delimiter);
			break ;
		}
		input = ft_strjoin(input, "\n");
	}
	free(input);
	return (result);
}

int	get_heredoc(char *delimiter)
{
	int		fd[2];
	char	*result;

	result = NULL;
	g_status = 0;
	if (pipe(fd) == -1)
	{
		throw_error(PIPERR, 1, NULL);
		return (-1);
	}
	result = get_string(delimiter);
	printf("res>> %s", result);
	write(fd[WRITE_END], result, ft_strlen(result));
	free(result);
	close(fd[WRITE_END]);
	if (g_status == 130)
	{
		close(fd[READ_END]);
		return (-1);
	}
	return (fd[READ_END]);
}
