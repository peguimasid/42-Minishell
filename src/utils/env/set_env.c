/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 11:49:11 by gmasid            #+#    #+#             */
/*   Updated: 2022/11/07 18:39:10 by gmasid           ###   ########.fr       */
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

char	*join_env(char *key, char *value)
{
	char	*aux1;
	char	*aux2;
	char	*result;

	aux1 = ft_strdup(key);
	aux2 = ft_strcat(aux1, "=");
	result = ft_strcat(aux2, value);
	free(aux1);
	free(aux2);
	return (result);
}

char	**change_env_value(int index, char *key, char *value, char **envp)
{
	char	*new_value;
	char	**result;

	new_value = join_env(key, value);
	result = matrix_replace(envp, index, new_value);
	free(new_value);
	return (result);
}

char	**add_new_env(char *key, char *value, char **envp)
{
	char	*variable_joined;
	char	**result;

	variable_joined = join_env(key, value);
	result = matrix_push(envp, variable_joined);
	free(variable_joined);
	return (result);
}

char	**set_env(char *key, char *value, char **envp)
{
	int	env_index;

	env_index = get_env_index(key, envp);
	printf("in => %d\n", env_index);
	if (env_index > -1)
		return (envp = change_env_value(env_index, key, value, envp));
	return (envp = add_new_env(key, value, envp));
}
