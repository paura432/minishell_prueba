/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pramos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 19:12:06 by pramos            #+#    #+#             */
/*   Updated: 2023/01/23 19:12:08 by pramos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*aux;

	aux = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!aux)
		return (0);
	i = 0;
	j = 0;
	while (s1[j] != 0)
		aux[i++] = *(char *)&s1[j++];
	j = 0;
	while (s2[j] != 0)
		aux[i++] = *(char *)&s2[j++];
	aux[i] = 0;
	return (aux);
}
