/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_separator.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucafern <lucafern@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 17:19:48 by lucafern          #+#    #+#             */
/*   Updated: 2022/11/05 19:58:10 by lucafern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	pipe_len(char *orig, char sep, const int i)
{
	int		tk_len;
	char	in_quotes;

	in_quotes = 0;
	tk_len = 0;
	while ((orig[i + tk_len] != sep || in_quotes) && orig[i + tk_len] != '\0')
	{
		if (!in_quotes && orig[i + tk_len] == '\"')
			in_quotes = '\"';
		else if (!in_quotes && orig[i + tk_len] == '\'')
			in_quotes = '\'';
		else if (in_quotes == '\"' && orig[i + tk_len] == '\"')
			in_quotes = 0;
		else if (in_quotes == '\'' && orig[i + tk_len] == '\'')
			in_quotes = 0;
		tk_len++;
	}
	return (tk_len);
}

// t_list	*pipe_separator(char *orig)
// {
// 	t_list	*pipe_cmds;
// 	int		i;
// 	int		len;

// 	pipe_cmds = NULL;
// 	i = 0;
// 	while (orig[i])
// 	{
// 		while (orig[i] == ' ' && orig[i])
// 			i++;
// 		if (orig[i])
// 		{
// 			if (orig[i] == '\"')
// 				len = pipe_len(orig, '\"', i);
// 			else if (orig[i] == '\'')
// 				len = pipe_len(orig, '\'', i);
// 			else
// 				len = pipe_len(orig, ' ', i);
// 			ft_lstadd_back(&pipe_cmds, ft_lstnew(ft_substr(&orig[i], 0, len)));
// 			i += len;
// 		}
// 	}
// 	return (pipe_cmds);
// }

t_list	*pipe_separator(char *orig)
{
	t_list	*pipe_cmds;
	int		i;
	int		len;

	pipe_cmds = NULL;
	i = 0;
	while (orig[i])
	{
		while (orig[i] == '|' && orig[i])
			i++;
		if (orig[i])
		{
			len = pipe_len(orig, '|', i);
			ft_lstadd_back(&pipe_cmds, ft_lstnew(ft_substr(&orig[i], 0, len)));
			i += len;
		}
	}
	return (pipe_cmds);
}

void	ft_print_lst(t_list *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		ft_printf("%p | ", lst);
		ft_printf("Node: %i | ", i);
		ft_printf("Content: %s | ", lst->content);
		ft_printf("Next: %p\n", lst->next);
		i++;
		if (lst->next == NULL)
			break ;
		lst = lst->next;
	}
}
