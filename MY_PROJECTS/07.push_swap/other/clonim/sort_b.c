/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbethany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 21:19:28 by kbethany          #+#    #+#             */
/*   Updated: 2019/08/30 21:19:38 by kbethany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

static int	varios(int b, int min, int max, t_stack *l)
{
	int	c;
	int	k;
	int	z;

	c = 0;
	k = 0;
	z = 0;
	while (c < l->ia)
	{
		if (l->va[c] < b && l->va[c] >= max)
		{
			max = l->va[c];
			k = c;
		}
		if (l->va[c] > b && l->va[c] <= min)
		{
			min = l->va[c];
			z = c;
		}
		c++;
	}
	if ((z == 0 && k == l->ia - 1) || (z == k + 1) || (k == 0 && z == 0))
		return (z);
	return (0);
}

static int	com_b(int b, int i, t_stack *l)
{
	if (b > l->ib - b && l->ib - b >= 0)
	{
		l->com_b[i] = 'R';
		return (l->ib - b);
	}
	else
		l->com_b[i] = 'r';
	return (b);
}

static int	com_a(int a, int i, t_stack *l)
{
	if (a > l->ia - a && l->ia - a >= 0)
	{
		l->com_a[i] = 'R';
		return (l->ia - a);
	}
	else
		l->com_a[i] = 'r';
	return (a);
}

void		sort_b(t_stack *l)
{
	int		i;
	int		a;
	int		b;

	i = 0;
	while (i < l->ib)
	{
		b = i;
		a = varios(l->vb[i], l->max, l->min, l);
		b = com_b(b, i, l);
		a = com_a(a, i, l);
		if ((l->int_b + l->int_a) > (b + a))
		{
			l->int_b = b;
			l->int_a = a;
			l->in = i;
		}
		i++;
	}
	if (l->int_a == 0)
		l->com_a[l->in] = '0';
	if (l->int_b == 0)
		l->com_b[l->in] = '0';
	sorter(l, l->com_a[l->in], l->com_b[l->in]);
}
