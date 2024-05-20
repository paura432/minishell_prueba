/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pramos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 12:36:15 by pramos            #+#    #+#             */
/*   Updated: 2023/01/13 12:36:18 by pramos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*aux1;
	unsigned char	*aux2;

	aux1 = (unsigned char *)dst;
	aux2 = (unsigned char *)src;
	if (!src && !dst)
		return (0);
	if (dst < src)
		return (ft_memcpy(dst, src, len));
	while (len--)
		aux1[len] = aux2[len];
	return (dst);
}
