/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfalia-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 14:52:34 by kfalia-f          #+#    #+#             */
/*   Updated: 2018/12/14 15:42:15 by kfalia-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f) (t_list *elem))
{
	t_list	*res;
	t_list	*h;
	t_list	*el;

	if (!lst || !f)
		return (NULL);
	el = f(lst);
	if (!(res = ft_lstnew(el->content, el->content_size)))
		return (NULL);
	lst = lst->next;
	h = res;
	while (lst)
	{
		el = f(lst);
		if (!(res->next = ft_lstnew(el->content, el->content_size)))
			return (NULL);
		res = res->next;
		lst = lst->next;
	}
	return (h);
}
