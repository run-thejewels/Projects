/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbethany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/24 16:17:58 by kbethany          #+#    #+#             */
/*   Updated: 2019/08/24 16:18:33 by kbethany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void        a_zero(t_stack *l)
{
	int i;

	i = 0;
	if (l->com_b == 'r')
		while (i < l->int_b)
		{
			rs(l, 'b');
			i++;
		}
	else
		while (i < l->int_b)
		{
			rrs(l, 'b');
			i++;
		}
}

void        b_zero(t_stack *l)
{
	int i;

	i = 0;
	if (l->com_a == 'r')
		while (i < l->int_a)
		{
			rs(l, 'a');
			i++;
		}
	else
		while (i < l->int_a)
		{
			rrs(l, 'a');
			i++;
		}
}

void        simetra(t_stack *l)
{
	int i;

	i = 0;
	if (l->com_a == 'r')
		while (i < l->int_a)
		{
			rs(l, 's');
			i++;
		}
	else
		while (i < l->int_a)
		{
			rrs(l, 's');
			i++;
		}
}

void        sim_a_bigger(t_stack *l)
{
	int i;

	i = 0;
	simetra(l);
	l->int_a = l->int_a - l->int_b;
	if (l->com_a == 'r')
		while (i < l->int_a)
		{
			rs(l, 'a');
			i++;
		}
	else
		while (i < l->int_a)
		{
			rrs(l, 'a');
			i++;
		}
}

void        sim_b_bigger(t_stack *l)
{
	int i;

	i = 0;
	simetra(l);
	l->int_b = l->int_b - l->int_a;
	if (l->com_a == 'r')
		while (i < l->int_b)
		{
			rs(l, 'b');
			i++;
		}
	else
		while (i < l->int_b)
		{
			rrs(l, 'b');
			i++;
		}
}

void        sorter(t_stack *l)
{
	int i;
	i = 0;
	if (l->com_a == '0' && l->com_b != '0')
		a_zero(l);
	else if (l->com_b == '0' &&l->com_a != '0')
		b_zero(l);
	else if (l->com_a == l->com_b)
	{
		if (l->int_a == l->int_b)
			simetra(l);
		else if (l->int_a > l->int_b)
			sim_a_bigger(l);
		else if (l->int_a < l->int_b)
			sim_b_bigger(l);
	}
	else if (l->com_a != l->com_b)
	{
		b_zero(l);
		a_zero(l);
	}
	pa(l);
}
