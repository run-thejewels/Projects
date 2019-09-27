/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsearch_cs_del.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 22:37:59 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/05/09 19:50:50 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstsearch_cs_del(t_list *lst, size_t cs)
{
	t_list	*temp;
	t_list	*begin;
	t_list	*result;

	if (!lst)
		return (NULL);
	temp = NULL;
	begin = lst;
	while (lst)
	{
		if (lst->content_size == cs)
		{
			result = lst->next;
			if (temp)
				temp->next = lst->next;
			ft_free_both(lst->content, (void *)lst);
			if (!temp)
				return (begin);
			else
				return (result);
		}
		temp = lst;
		lst = lst->next;
	}
	return (begin);
}
