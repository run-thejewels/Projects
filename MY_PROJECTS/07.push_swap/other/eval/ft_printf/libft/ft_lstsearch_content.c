/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsearch_content.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 00:34:49 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/02/19 00:19:34 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstsearch_content(t_list *lst, \
	void *to_search, size_t search_size)
{
	if (!lst || !to_search || !search_size)
		return (NULL);
	while (lst)
	{
		if (lst->content_size == search_size)
		{
			if (!ft_memcmp(to_search, lst->content, search_size))
				return (lst);
		}
		lst = lst->next;
	}
	return (NULL);
}
