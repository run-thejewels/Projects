/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsabre-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 20:37:59 by bsabre-c          #+#    #+#             */
/*   Updated: 2018/12/12 14:30:18 by bsabre-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new_lst;
	t_list	*dst;

	if (!lst || !f)
		return (NULL);
	new_lst = f(lst);
	dst = new_lst;
	while (lst->next)
	{
		lst = lst->next;
		if (!(new_lst->next = f(lst)))
		{
			while (dst)
			{
				new_lst = dst;
				dst = dst->next;
				free(new_lst);
			}
			return (NULL);
		}
		new_lst = new_lst->next;
	}
	return (dst);
}
