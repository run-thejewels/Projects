/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsearch_index.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 06:02:59 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/02/20 06:03:03 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstsearch_index(t_list *lst, size_t index)
{
	if (!lst)
		return (NULL);
	while (index)
	{
		if (lst->next)
			lst = lst->next;
		else if (!(lst->next) && index == 1)
			break ;
		else
			return (NULL);
		index--;
	}
	return (lst);
}
