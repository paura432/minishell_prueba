/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pramos <pramos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 19:41:02 by pramos            #+#    #+#             */
/*   Updated: 2023/02/13 18:53:18 by pramos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"
#include<stdio.h>

static int	ft_filas(char *s, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[j] != 0)
	{
		while (s[j] == c)
			j++;
		if (s[j] != c && s[j] != 0)
		{
			i++;
			while (s[j] != c && s[j] != 0)
				j++;
		}
	}
	return (i);
}

static void	ft_free(char **matriz, int i)
{
	while (i-- > 0)
		free(matriz[i]);
	free(matriz);
}

static char	**ft_matrtiz(char *s, char **matriz, char c, int i)
{
	int	j;
	int	k;

	k = 0;
	while (s[i])
	{
		while (*(char *)&s[i] == c)
			i++;
		j = i;
		while (s[i] != 0 && *(char *)&s[i] != c)
			i++;
		if (i > j)
		{
			matriz[k] = ft_substr(s, j, (i - j));
			if (!matriz[k])
			{
				ft_free(matriz, k);
				return (NULL);
			}
			k++;
		}
	}
	matriz[k] = 0;
	return (matriz);
}

char	**ft_split(char const *s, char c)
{
	char	**matriz;
	int		i;

	i = 0;
	matriz = (char **)malloc((ft_filas((char *)s, c) + 1) * sizeof(char *));
	if (!matriz)
		return (0);
	matriz = ft_matrtiz((char *)s, matriz, c, i);
	return (matriz);
}

/*int main()
{
	int i;
	char **matriz;

	i = 0;
	matriz = ft_split(",,,,hola,,,,que,tal", ',');
	while (matriz[i][0] != 0)
	{
		printf("%s", matriz[i]);
		printf("%s", "\n");
		i++;
	}
	printf("%s", matriz[i]);
	return (0);
}
*/