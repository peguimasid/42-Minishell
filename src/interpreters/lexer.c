/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucafern <lucafern@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 17:19:48 by lucafern          #+#    #+#             */
/*   Updated: 2022/11/05 17:56:29 by lucafern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	**lexer(char *line_orig)
{
	char	**tokens;

	tokens = ft_split(line_orig, ' ');
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

t_list	*init_lst(char *arguments[])
{
	int i;
	t_list *list;

	list = NULL;
	i = 0;
	while (arguments[i])
	{
		ft_lstadd_back(&list, ft_lstnew(arguments[i]));
		i++;
	}
	return (list);
}