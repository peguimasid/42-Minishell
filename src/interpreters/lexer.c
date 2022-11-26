/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucafern <lucafern@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 17:19:48 by lucafern          #+#    #+#             */
/*   Updated: 2022/11/26 12:32:53 by lucafern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	token_len(char *orig, char sep, const int i)
{
	int	tk_len;

	tk_len = 0;
	if (ft_strchr("\"\'", sep))
		tk_len++;
	while (orig[i + tk_len] != sep && orig[i + tk_len] != '\0')
		tk_len++;
	if (ft_strchr("\"\'", sep))
		tk_len++;
	return (tk_len);
}

t_list	*lexer(char *orig)
{
	t_list	*tokens;
	int		i;
	int		len;

	tokens = NULL;
	i = 0;
	while (orig[i])
	{
		while (orig[i] == ' ' && orig[i])
			i++;
		if (orig[i])
		{
			if (orig[i] == '\"')
				len = token_len(orig, '\"', i);
			else if (orig[i] == '\'')
				len = token_len(orig, '\'', i);
			else
				len = token_len(orig, ' ', i);
			ft_lstadd_back(&tokens, ft_lstnew(ft_substr(&orig[i], 0, len)));
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
