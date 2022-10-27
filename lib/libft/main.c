/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucafern <lucasfads@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 14:40:20 by lucafern          #+#    #+#             */
/*   Updated: 2022/05/07 14:40:20 by lucafern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "libft.h"

int main ()
{
	// printf("%li\n", ft_strlen("opa"));

	// char dest[100] = "ola colegas";
	// char src[100] = "oie";
	// int i = 0;
	// ft_memcpy(dest, src, 3);
	// while (dest[i])
	// {
	// 	printf("%c", dest[i]);
	// 	i++;
	// }
	// printf("\n");

	// char dest[100] = "ola colegas";
	// char src[100] = "oie";
	// int i = 0;
	// ft_memmove(dest, src, 3);
	// while (dest[i])
	// {
	// 	printf("%c", dest[i]);
	// 	i++;
	// }
	// printf("\n");

	// printf("%c\n", ft_toupper('a'));
	// printf("%c\n", ft_tolower('B'));

	// printf("%s\n", ft_strchr("ola Amigos", 'A'));

	// printf("%s\n", ft_strrchr("ola Amigo Avulsos", 'A'));

	// char *string = "ola colegas";
	// char character = 'c';
	// int i = 0;
	// char *new_string = ft_memchr(string, character, 7);
	// while (new_string[i])
	// {
	// 	printf("%c", new_string[i]);
	// 	i++;
	// }
	// printf("\n");

	// printf("%i\n", ft_memcmp("ola", "ole", 3));

	char 	test1[] = {"PeraUvaMacaMelancia"};
	char 	test2[] = {"Uva"};
	char 	*result_test;

	result_test = ft_strnstr(test1, test2, 19);
	printf("%s\n", result_test);
}
