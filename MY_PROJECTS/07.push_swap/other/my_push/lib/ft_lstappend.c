/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstappend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademenet <ademenet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/16 17:27:21 by ademenet          #+#    #+#             */
/*   Updated: 2016/05/19 11:52:40 by ademenet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_plst			*ft_lstappend(t_plst *list, int v)
{
	t_node		*new;

	if (list != NULL)
	{
		if ((new = (t_node*)malloc(sizeof(t_node))) != NULL)
		{
			new->v = v;
			new->next = NULL;
			if (list->tail == NULL)
			{
				list->head = new;
				list->tail = new;
			}
			else
			{
				list->tail->next = new;
				list->tail = new;
			}
			list->len++;
		}
	}
	return (list);
}
