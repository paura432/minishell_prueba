/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pramos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 13:15:10 by pramos            #+#    #+#             */
/*   Updated: 2023/01/16 13:15:11 by pramos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, char *src, size_t dstsize)
{
	size_t	len;

	len = 0;
	if (dstsize == 0)
		return (ft_strlen(src));
	while (src[len] != '\0' && len < (dstsize - 1))
	{
		dst[len] = src[len];
		len++;
	}
	dst[len] = '\0';
	while (src[len] != '\0')
		len++;
	return (ft_strlen(src));
}
