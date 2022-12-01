/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucafern <lucafern@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 10:52:59 by gmasid            #+#    #+#             */
/*   Updated: 2022/12/01 12:41:32 by lucafern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

extern int	g_status;

char	*get_substr_var(char *str, int i, t_data *data)
{
	char	*aux;
	int		pos;
	char	*path;
	char	*var;
	int		var_len;

	pos = ft_strchars_i(str + i, "|\"\'$?>< ") + (ft_strchr("$?", str[i]) != 0);
	if (pos == -1)
		pos = ft_strlen(str) - 1;
	aux = ft_substr(str, 0, i - 1);
	var_len = ft_strchars_i(str + i, "\"\'$|>< ");
	var = get_env(str + i, data->envp, var_len);
	if (!var && str[i] == '$')
		var = ft_itoa(data->pid);
	else if (!var && str[i] == '?')
		var = ft_itoa(g_status);
	path = ft_strjoin(aux, var);
	free(aux);
	aux = ft_strjoin(path, str + i + pos);
	free(var);
	free(path);
	free(str);
	return (aux);
}

char	*get_substr_path(char *str, int i, t_data *data)
{
	char	*aux;
	char	*path;
	char	*var;

	aux = ft_substr(str, 0, i);
	var = get_env("HOME", data->envp, 4);
	path = ft_strjoin(aux, var);
	free(aux);
	aux = ft_substr(str, i + 1, ft_strlen(str));
	free(str);
	str = ft_strjoin(path, aux);
	free(aux);
	free(path);
	free(var);
	return (str);
}
