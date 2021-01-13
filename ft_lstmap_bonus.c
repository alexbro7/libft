/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebross <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 18:29:00 by alebross          #+#    #+#             */
/*   Updated: 2019/11/15 20:02:41 by alebross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*frst;
	t_list	*new;
	t_list	*next;

	if (!lst)
		return (NULL);
	if (!(new = ft_lstnew(f(lst->content))))
		return (NULL);
	frst = new;
	lst = lst->next;
	while (lst)
	{
		if (!(next = ft_lstnew(f(lst->content))))
		{
			ft_lstclear(&frst, del);
			return (NULL);
		}
		new->next = next;
		new = new->next;
		lst = lst->next;
	}
	return (frst);
}
