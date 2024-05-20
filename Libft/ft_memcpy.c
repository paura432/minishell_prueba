/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pramos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 11:45:27 by pramos            #+#    #+#             */
/*   Updated: 2023/01/13 11:45:35 by pramos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*aux;

	printf("fuera");
	printf("esto %p", src);
	aux = dst;
	if (!dst && !src)
		return (0);
	while (n > 0)
	{

		*aux++ = *(unsigned char *)src++;
		n--;
	}

	return (dst);
}
