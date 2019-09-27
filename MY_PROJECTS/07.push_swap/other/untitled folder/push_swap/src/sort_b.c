/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbethany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/24 16:15:17 by kbethany          #+#    #+#             */
/*   Updated: 2019/08/24 16:17:28 by kbethany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void        sort_b(t_stack* l)
{
	int i;
	int a;
	int b;

	i = 0;
	b = 0;
	a = 0;
	while (i < l->ib - 1)
	{
		b = i;
		l->com_b = 'r';
		if (i > l->ib - i && l->ib - i >= 0)
		{
			b = l->ib - i;
			l->com_b = 'R';
		}
		a = sort_a(l->vb[i], l);
		if ((l->int_b + l->int_a) >= (b + a))
		{
			l->int_b = b;
			l->int_a = a;
			l->in = i;
		}
		i++;
	}
	l->int_a = sort_a(l->vb[l->in], l);
	if (l->int_b == 0 || l->ib < 2)
		l->com_b = '0';
	sorter(l);
	reset(l);
}
