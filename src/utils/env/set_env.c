/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 11:49:11 by gmasid            #+#    #+#             */
/*   Updated: 2022/11/06 13:32:21 by gmasid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

char	*ft_strcat(char *src, char *dest)
{
	int		i;
	int		y;
	int		len;
	char	*result;

	i = 0;
	y = 0;
	len = (ft_strlen(src) + ft_strlen(dest));
	result = malloc(sizeof(char) * len + 1);
	while (src[i] != '\0')
	{
		result[i] = src[i];
		i++;
	}
	while (dest[y] != '\0')
	{
		result[i] = dest[y];
		i++;
		y++;
	}
	result[i] = '\0';
	return (result);
}

// TODO:
// Create function to return the index or -1 if env not exists
// EXISTS: Free old var and store new in the place
// NOT EXISTS: Call matrix push in new var
char	**set_env(char *key, char *value, char **envp)
{
	char	*aux1;
	char	*aux2;
	char	*new_var;

	aux1 = ft_strdup(key);
	aux2 = ft_strcat(aux1, "=");
	new_var = ft_strcat(aux2, value);
	envp = matrix_push(envp, new_var);
	free(aux1);
	free(aux2);
	free(new_var);
	return (envp);
}
