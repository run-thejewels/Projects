/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simetra.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbethany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 21:36:44 by kbethany          #+#    #+#             */
/*   Updated: 2019/08/30 21:38:35 by kbethany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

int		simetra(t_stack *l)
{
	int i;

	i = 0;
	if (l->int_a == 0 || l->int_b == 0)
		return (0);
	if (l->com_a[l->in] == 'r')
		while (i < l->int_a)
		{
			rr(l, 's');
			i++;
		}
	else
		while (i < l->int_a)
		{
			rrs(l, 's');
			i++;
		}
	return (0);
}

int		simetrb(t_stack *l)
{
	int	i;

	i = 0;
	if (l->int_b == 0 || l->int_a == 0)
		return (0);
	if (l->com_b[l->in] == 'r')
		while (i < l->int_b)
		{
			rr(l, 's');
			i++;
		}
	else
		while (i < l->int_b)
		{
			rrs(l, 's');
			i++;
		}
	return (0);
}

void	sim_a_bigger(t_stack *l)
{
	int	i;

	i = 0;
	simetrb(l);
	l->int_a = l->int_a - l->int_b;
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

void	sim_b_bigger(t_stack *l)
{
	int	i;

	i = 0;
	simetra(l);
	l->int_b = l->int_b - l->int_a;
	if (l->com_a[l->in] == 'r')
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
