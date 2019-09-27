/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsearch_cs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 00:35:31 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/02/19 00:09:51 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstsearch_cs(t_list *lst, size_t cs)
{
	t_list	*temp;

	temp = lst;
	while (temp)
	{
		if (temp->content_size == cs)
			return (temp);
		temp = temp->next;
	}
	return (NULL);
}
