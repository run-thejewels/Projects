/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_optimization.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademenet <ademenet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/23 10:26:01 by ademenet          #+#    #+#             */
/*   Updated: 2016/05/30 11:37:06 by ademenet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*
** We wan't to use the minimums moves: so if I know where is localized my node
** I could use either rotate or reverse rotate. To do so, we return list length
** ratio / position.
*/

int			ft_locateit(t_plst *l, int min)
{
	t_node	*tmp;
	int		index;

	tmp = l->head;
	index = 1;
	while (tmp->next != NULL && tmp->v != min)
	{
		index++;
		tmp = tmp->next;
	}
	return (l->len / index);
}

/*
** This function is useful only if my list is sorted but the minimum value is
** not set to list start.
*/

t_plst		*ft_isreverse(t_plst *l, t_plst *mv)
{
	int		pos;
	int		min;

	min = ft_findmin(l);
	pos = ft_locateit(l, min);
	if (pos > 2)
	{
		while (ft_issortasc(l) == 1)
			mv = ft_revrotate(l, mv, 0);
	}
	else if (pos <= 2)
	{
		while (ft_issortasc(l) == 1)
			mv = ft_rotate(l, mv, 0);
	}
	return (mv);
}
