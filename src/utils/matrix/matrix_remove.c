/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_remove.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucafern <lucafern@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
<<<<<<< HEAD:src/builtins/cd.c
/*   Created: 2022/10/26 12:46:30 by gmasid            #+#    #+#             */
/*   Updated: 2022/11/01 14:42:19 by lucafern         ###   ########.fr       */
=======
/*   Created: 2022/12/09 19:13:15 by gmasid            #+#    #+#             */
/*   Updated: 2022/12/09 19:22:07 by gmasid           ###   ########.fr       */
>>>>>>> 94d5e82586533380ec0faa173c0bd303ef15f2b8:src/utils/matrix/matrix_remove.c
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

<<<<<<< HEAD:src/builtins/cd.c
void	update_pwd(t_data *data)
{
	char	cwd[PATH_MAX];

	getcwd(cwd, sizeof(cwd));
	set_env(data, ft_strdup("OLDPWD"), ft_strdup(get_env(data, "PWD")));
	set_env(data, ft_strdup("PWD"), ft_strdup(cwd));
}

void	change_directory(t_data *data, char **args)
{
	char	*path;

	if (!args[1])
	{
		path = get_env(data, "HOME");
		if (chdir(path) != 0)
			perror("Error");
		update_pwd(data);
		return ;
	}
	if (args[2])
	{
		printf("cd: string not in pwd: %s\n", args[1]);
		return ;
	}
	if (chdir(args[1]) != 0)
		printf("%s: %s\n", strerror(errno), args[1]);
	update_pwd(data);
=======
char	**matrix_remove(char **matrix, int to_remove)
{
	char	**result;
	int		i;
	int		j;
	int		len;

	if (!matrix || !matrix[to_remove])
		return (matrix);
	i = 0;
	j = 0;
	len = matrix_len(matrix);
	result = malloc(sizeof(char *) * (len));
	result[len] = NULL;
	if (!result)
		return (matrix);
	while (i < len)
	{
		if (i != to_remove)
			result[j++] = ft_strdup(matrix[i]);
		i++;
	}
	free_matrix(matrix);
	return (result);
>>>>>>> 94d5e82586533380ec0faa173c0bd303ef15f2b8:src/utils/matrix/matrix_remove.c
}
