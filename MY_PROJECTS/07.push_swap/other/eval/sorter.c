/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbethany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 17:55:18 by kbethany          #+#    #+#             */
/*   Updated: 2019/08/31 14:55:15 by kbethany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

static void	a_zero(t_stack *l)
{
	int	i;

	i = 0;
	if (l->com_b[l->in] == 'r')
		while (i < l->int_b)
		{
			rr(l, 'b');
			i++;
		}
	else
		while (i < l->int_b)
		{
			rrs(l, 'b');
			i++;
		}
}

static void	b_zero(t_stack *l)
{
	int	i;

	i = 0;
	if (l->com_a[l->in] == 'r')
		while (i < l->int_a)
		{
			rr(l, 'a');
			i++;
		}
	else
		while (i < l->int_a)
		{
			rrs(l, 'a');
			i++;
		}
}

void		sorter(t_stack *l, char a, char b)
{
	int	i;

	i = 0;
	if (l->int_a == 0 && l->int_b > 0)
		a_zero(l);
	else if (l->int_b == 0 && l->int_a > 0)
		b_zero(l);
	else if (a == b && (l->int_a != 0 || l->int_b != 0))
	{
		if (l->int_a == l->int_b)
			simetra(l);
		else if (l->int_a > l->int_b)
			sim_a_bigger(l);
		else if (l->int_a < l->int_b)
			sim_b_bigger(l);
	}
	else if (a != b)
	{
		b_zero(l);
		a_zero(l);
	}
	pa(l);
}
