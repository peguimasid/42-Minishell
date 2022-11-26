/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 12:16:57 by gmasid            #+#    #+#             */
/*   Updated: 2022/11/26 10:29:59 by gmasid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static char	*get_substr_var(char *str, int i, t_data *data)
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

int	should_be_expanded(char *str, int i, int sq_open, int dq_open)
{
	int	found_forbidden_char_after_dollar;
	int	not_has_dq_case_trated;
	int	has_dq_case_trated;

	if (sq_open || str[i] != '$' || !str[i + 1])
		return (0);
	found_forbidden_char_after_dollar = ft_strchars_i(str + i + 1, "/~%^{}:;");
	if (found_forbidden_char_after_dollar == 0)
		return (0);
	not_has_dq_case_trated = (ft_strchars_i(str + i + 1, " ") && !dq_open);
	has_dq_case_trated = (ft_strchars_i(str + i + 1, "\"") && dq_open);
	return (not_has_dq_case_trated || has_dq_case_trated);
}

char	*expand_vars(char *str, t_data *data)
{
	int	sq_open;
	int	dq_open;
	int	i;

	sq_open = 0;
	dq_open = 0;
	i = 0;
	while (str && str[i])
	{
		sq_open = (sq_open + (!dq_open && str[i] == SINGLE_QUOTE)) % 2;
		dq_open = (dq_open + (!sq_open && str[i] == DOUBLE_QUOTE)) % 2;
		if (should_be_expanded(str, i, sq_open, dq_open))
			return (expand_vars(get_substr_var(str, ++i, data), data));
		i++;
	}
	return (str);
}
