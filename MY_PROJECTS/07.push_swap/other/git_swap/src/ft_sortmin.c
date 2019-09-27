/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sortmin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademenet <ademenet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/18 10:45:20 by ademenet          #+#    #+#             */
/*   Updated: 2016/05/30 14:12:36 by ademenet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*
** This sortmin alogrithm is a kind of bubble sort. We are looking for the
** minimum value and we rotate it up so as to push it in our second stack.
** With some magic crunch of codes, it gives us an sorted array.
*/

/*
** Finding the minimum. Not a big deal but it could cost O(n) operations.
*/

int				ft_findmin(t_plst *l)
{
	t_node		*tmp;
	int			min;

	tmp = l->head;
	min = tmp->v;
	while (tmp)
	{
		if (tmp->v < min)
			min = tmp->v;
		tmp = tmp->next;
	}
	return (min);
}

/*
** Crunch of optimization. If my minimum value is more located in the fisrt part
** of my array then we use rotate (faster). Otherwise... reverse rotate. You got
** it!
*/

static t_plst	*ft_bubble(t_plst *la, t_plst *mv, int min)
{
	int			pos;

	pos = ft_locateit(la, min);
	if (pos > 2)
	{
		while (la->head->v != min)
			mv = ft_rotate(la, mv, 0);
	}
	else if (pos <= 2)
	{
		while (la->head->v != min)
			mv = ft_revrotate(la, mv, 0);
	}
	return (mv);
}

/*
** I'm looking for the minimum then let it climb the list and push it in
** b-stack. Yep, it's cruel.
*/

t_plst			*ft_sortmin(t_plst *la, t_plst *lb, t_plst *mv)
{
	t_node		*ta;
	t_node		*tb;
	int			min;

	ta = la->head;
	tb = lb->head;
	while (la->len > 0)
	{
		min = ft_findmin(la);
		mv = ft_bubble(la, mv, min);
		mv = ft_push_b(la, lb, mv);
	}
	while (lb->len > 0)
		mv = ft_push_a(la, lb, mv);
	return (mv);
}
