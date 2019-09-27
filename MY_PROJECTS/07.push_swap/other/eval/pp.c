/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pp.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbethany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 21:52:20 by kbethany          #+#    #+#             */
/*   Updated: 2019/08/30 21:53:29 by kbethany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

int	pa(t_stack *l)
{
	int	i;

	if (l->ib == 0)
		return (0);
	i = l->ia;
	l->ia++;
	while (i >= 0)
	{
		l->va[i + 1] = l->va[i];
		i--;
	}
	l->va[0] = l->vb[0];
	i = 0;
	while (i < l->ib)
	{
		l->vb[i] = l->vb[i + 1];
		i++;
	}
	l->ib--;
	comnew(l, "pa\n");
	return (0);
}

int	pv(t_stack *l)
{
	int	i;

	if (l->ib == 0)
		return (0);
	i = l->iv;
	l->iv++;
	while (i >= 0)
	{
		l->vv[i + 1] = l->vv[i];
		i--;
	}
	l->vv[0] = l->vb[0];
	i = 0;
	while (i < l->ib)
	{
		l->vb[i] = l->vb[i + 1];
		i++;
	}
	l->ib--;
	return (0);
}

int	pb(t_stack *l)
{
	int	i;

	if (l->ia == 0)
		return (0);
	i = l->ib;
	l->ib++;
	while (i >= 0)
	{
		l->vb[i + 1] = l->vb[i];
		i--;
	}
	l->vb[0] = l->va[0];
	i = 0;
	while (i < l->ia)
	{
		l->va[i] = l->va[i + 1];
		i++;
	}
	l->ia--;
	comnew(l, "pb\n");
	return (0);
}

int	pvb(t_stack *l)
{
	int	i;

	if (l->iv == 0)
		return (0);
	i = l->ib;
	l->ib++;
	while (i >= 0)
	{
		l->vb[i + 1] = l->vb[i];
		i--;
	}
	l->vb[0] = l->vv[0];
	i = 0;
	while (i < l->iv)
	{
		l->vv[i] = l->vv[i + 1];
		i++;
	}
	l->iv--;
	return (0);
}
