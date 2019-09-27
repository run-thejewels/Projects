/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstutils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademenet <ademenet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/26 16:20:47 by ademenet          #+#    #+#             */
/*   Updated: 2016/05/28 18:37:43 by ademenet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void		ft_lstdellastone(t_plst *l)
{
	t_node	*tmp;
	t_node	*del;

	if (l->head != l->tail)
	{
		tmp = l->head;
		while (tmp->next != l->tail)
			tmp = tmp->next;
		del = l->tail;
		l->tail = tmp;
		l->tail->next = NULL;
		free(del);
		l->len--;
	}
}

void		ft_lstdelallnodes(t_plst *l)
{
	t_node	*tmp;
	t_node	*del;

	if (l->head != NULL)
	{
		tmp = l->head;
		while (tmp)
		{
			del = tmp;
			tmp = tmp->next;
			free(del);
		}
		l->head = NULL;
		l->tail = NULL;
		l->len = 0;
	}
}

void		ft_lstclear(t_plst *l)
{
	ft_lstdelallnodes(l);
	free(l);
}
