/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pramos <pramos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 19:58:40 by pramos            #+#    #+#             */
/*   Updated: 2023/02/13 17:19:10 by pramos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include<stdio.h>

char	*ft_strtrim(const char *s1, const char *set)
{
	size_t	i;
	size_t	j;
	char	*aux;

	i = 0;
	if (!s1 || !set)
		return (0);
	j = ft_strlen(s1);
	while (j >= i && ft_strchr(set, (int)s1[i]))
		i++;
	if (j <= i)
	{
		aux = (char *)malloc(sizeof(char));
		if (!aux)
			return (0);
		aux[0] = 0;
		return (aux);
	}
	while (j >= i && ft_strchr(set, (int)s1[j]))
		j--;
	aux = (char *)malloc((j - i + 2) * sizeof(char));
	if (!aux)
		return (0);
	ft_strlcpy(aux, (char *)&s1[i], j - i + 2);
	return (aux);
}


int main (void)
{
	printf("%s", ft_strtrim("holxad", "xa"));
	return(0);
}
