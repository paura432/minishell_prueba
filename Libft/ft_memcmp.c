/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pramos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 13:06:51 by pramos            #+#    #+#             */
/*   Updated: 2023/01/18 13:06:56 by pramos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (*(unsigned char *)s2 != *(unsigned char *)s1)
			return (*(unsigned char *)s1 - *(unsigned char *)s2);
		else
		{
			i++;
			s1++;
			s2++;			
		}
	}
	return (0);
}
