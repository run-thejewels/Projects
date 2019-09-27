/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ss.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbethany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 21:50:25 by kbethany          #+#    #+#             */
/*   Updated: 2019/08/30 21:51:39 by kbethany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

int	ss(t_stack *l, char a)
{
	if (a == 'a')
	{
		sa(l);
		comnew(l, "sa\n");
	}
	else if (a == 'v')
		sv(l);
	else if (a == 'b')
	{
		sb(l);
		comnew(l, "sb\n");
	}
	if (a == 's')
	{
		sa(l);
		sb(l);
		comnew(l, "ss\n");
	}
	return (0);
}

int	sa(t_stack *l)
{
	int	tmp;

	if (l->ia < 2)
		return (0);
	tmp = l->va[0];
	l->va[0] = l->va[1];
	l->va[1] = tmp;
	return (1);
}

int	sv(t_stack *l)
{
	int	tmp;

	if (l->iv < 2)
		return (0);
	tmp = l->vv[0];
	l->vv[0] = l->vv[1];
	l->vv[1] = tmp;
	return (1);
}

int	sb(t_stack *l)
{
	int	tmp;

	if (l->ib < 2)
		return (0);
	tmp = l->vb[0];
	l->vb[0] = l->vb[1];
	l->vb[1] = tmp;
	return (0);
}
