/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 12:16:57 by gmasid            #+#    #+#             */
/*   Updated: 2022/11/26 10:59:26 by gmasid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	should_var_be_expanded(char *str, int i, int sq_open, int dq_open)
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
		if (should_var_be_expanded(str, i, sq_open, dq_open))
			return (expand_vars(get_substr_var(str, ++i, data), data));
		i++;
	}
	return (str);
}

int	should_path_be_expanded(char *str, int i, int sq_open, int dq_open)
{
	if (sq_open || dq_open)
		return (0);
	if (str[i] != '~')
		return (0);
	if (i != 0 && str[i - 1] == '$')
		return (0);
	return (1);
}

char	*expand_path(char *str, t_data *data)
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
		if (should_path_be_expanded(str, i, sq_open, dq_open))
			return (expand_path(get_substr_path(str, i, data), data));
		i++;
	}
	return (str);
}
