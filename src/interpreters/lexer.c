/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucafern <lucafern@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 17:19:48 by lucafern          #+#    #+#             */
/*   Updated: 2022/11/05 19:23:43 by lucafern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_list	*lexer(char *line_orig)
{
	t_list	*tokens;
	int		i;
	int		len;

	tokens = NULL;
	i = 0;
	while (line_orig[i])
	{
		while (line_orig[i] == ' ' && line_orig[i])
			i++;
		if (line_orig[i])
		{
			len = 0;
			if (line_orig[i] == '\"')
			{
				len++;
				while (line_orig[i + len] != '\"' && line_orig[i + len] != '\0')
					len++;
				len++;
			}
			else if (line_orig[i] == '\'')
			{
				len++;
				while (line_orig[i + len] != '\'' && line_orig[i + len] != '\0')
					len++;
				len++;
			}
			else
			{
				while (line_orig[i + len] != ' ' && line_orig[i + len] != '\0')
					len++;
			}
			ft_lstadd_back(&tokens, ft_lstnew(ft_substr(&line_orig[i], 0,
							len)));
			i += len;
		}
	}
	return (tokens);
}

void	ft_print_lst(t_list *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		ft_printf("%p | ", lst);
		ft_printf("Node: %i | ", i);
		ft_printf("Content (Index): %s | ", lst->content);
		ft_printf("Next: %p\n", lst->next);
		i++;
		if (lst->next == NULL)
			break ;
		lst = lst->next;
	}
}
