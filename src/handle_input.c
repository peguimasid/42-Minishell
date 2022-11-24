/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 16:35:26 by gmasid            #+#    #+#             */
/*   Updated: 2022/11/24 12:28:47 by gmasid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	handle_input(t_data *data)
{
	char	**args;
	int		i;
	char	*str;

	if (!data->input)
		return (0);
	save_history(data->input);
	args = split_quotes(data->input, " ");
	str = get_env("PATH", data->envp);
	printf(">> %s\n", str);
	free(str);
	free(data->input);
	if (!args)
		return (throw_error(QUOTE, 1, NULL));
	i = 0;
	while (args[i])
	{
		free(args[i++]);
	}
	free(args);
	return (1);
}
