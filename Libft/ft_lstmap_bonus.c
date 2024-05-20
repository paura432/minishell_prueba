/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pramos <pramos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 11:32:01 by pramos            #+#    #+#             */
/*   Updated: 2023/02/08 18:47:16 by pramos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

static void	*ft_free(void *contenido, t_list *new, void (*del)(void *))
{
	del(contenido);
	ft_lstclear(&new, del);
	return (0);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*aux;
	t_list	*aux1;
	t_list	*new;
	void	*contenido;

	if (!f || !lst || !del)
		return (0);
	aux = 0;
	new = aux;
	aux1 = lst;
	while (aux1)
	{
		contenido = f(aux1->content);
		if (!contenido)
			new = ft_free(contenido, new, del);
		aux = ft_lstnew(contenido);
		if (!aux)
			new = ft_free(contenido, new, del);
		aux1 = aux1->next;
		ft_lstadd_back(&new, aux);
	}
	return (new);
}
