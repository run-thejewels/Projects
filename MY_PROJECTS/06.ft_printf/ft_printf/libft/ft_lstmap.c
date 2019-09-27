/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/25 15:34:34 by ahalmon-          #+#    #+#             */
/*   Updated: 2018/12/25 15:42:01 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*error_processing(t_list *first_elem)
{
	ft_lst_free_chain(first_elem);
	return (NULL);
}

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list		*temp;
	t_list		*new_list;
	t_list		*previous_list;
	t_list		*first_elem;

	if (!lst || !f)
		return (NULL);
	previous_list = f(lst);
	first_elem = previous_list;
	while (lst->next)
	{
		temp = lst->next;
		if (!(new_list = f(temp)))
			return (error_processing(first_elem));
		previous_list->next = new_list;
		previous_list = previous_list->next;
		lst = lst->next;
	}
	return (first_elem);
}
