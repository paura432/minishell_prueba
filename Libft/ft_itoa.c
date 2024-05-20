/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pramos <pramos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 17:50:08 by pramos            #+#    #+#             */
/*   Updated: 2023/03/14 17:09:10 by pramos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

static int	ft_lenint(int n)
{
	int	i;

	i = 0;
	if (n == 0)
		i++;
	if (n < 0)
	{
		n *= -1;
		i++;
	}
	while (n > 0)
	{
		i++;
		n /= 10;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*str;
	long	len;
	long	j;

	j = n;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	len = ft_lenint(j);
	if (n < 0)
		j *= -1;
	str = malloc(len + 1 * sizeof(char));
	if (!str)
		return (0);
	str[len] = 0;
	while (len > 0)
	{
		str[len - 1] = (j % 10) + 48;
		j /= 10;
		len--;
	}
	if (n < 0)
			str[len] = '-';
	return (str);
}
