/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbethany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 19:32:22 by kbethany          #+#    #+#             */
/*   Updated: 2019/08/31 21:56:21 by kbethany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

void	sort_tribus(t_stack *l)
{
	if (l->va[2] < l->va[1] && l->va[2] > l->va[0])
	{
		rrs(l, 'a');
		ss(l, 'a');
	}
	else if (l->va[2] > l->va[1] && l->va[2] < l->va[0])
		rr(l, 'a');
	else if (l->va[0] > l->va[1] && l->va[0] < l->va[2])
		ss(l, 'a');
	else if (l->va[0] > l->va[2] && l->va[0] < l->va[1])
		rrs(l, 'a');
	else if (l->va[1] < l->va[0] && l->va[1] > l->va[2])
	{
		rrs(l, 'a');
		ss(l, 'a');
	}
}

int		ideal(t_stack *l)
{
	int	i;

	i = 0;
	while (i < l->ia)
	{
		if ((l->va[i] != l->max && l->va[i + 1] != l->min) &&
			l->va[i] > l->va[i + 1])
			return (0);
		if (i < l->ia - 1 && l->va[i] == l->max && l->va[i + 1] != l->min)
			return (0);
		i++;
	}
	if (l->va[l->ia - 1] > l->va[0] && l->va[l->ia - 1] != l->max)
		return (0);
	return (1);
}

void	reset(t_stack *l)
{
	int	i;

	i = 0;
	while (l->va[i] != l->min)
		i++;
	if (i > l->ia / 2)
	{
		i = l->ia - i;
		l->com_a[l->in] = 'R';
	}
	else
		l->com_a[l->in] = 'r';
	while (i)
	{
		if (l->com_a[l->in] == 'r')
			rr(l, 'a');
		else if (l->com_a[l->in] == 'R')
			rrs(l, 'a');
		i--;
	}
}

void	alg(t_stack *l)
{
	while (l->ia > 3)
	{
		if (l->va[0] != l->min && l->va[0] != l->max)
			pb(l);
		else
			rr(l, 'a');
	}
	if (l->ia < 4)
		sort_tribus(l);
	while (l->ib)
	{
		l->int_a = l->max + 1;
		l->int_b = l->max;
		l->in = 0;
		sort_b(l);
	}
	reset(l);
	shreder_plusultra(l);
}

void	display_com(t_stack *l, char *a)
{
	int i;

	i = 0;
	ft_printf("\n=========================================================\n");
	ft_printf("com: %s\n elm: %d\n\nA: ", a, l->iv);
	while (i < l->iv)
	{
		ft_printf(" % d", l->vv[i]);
		i++;
	}
	i = 0;
	ft_printf("\nB: ");
	while (i < l->ib)
	{
		ft_printf(" % d", l->vb[i]);
		i++;
	}
	ft_printf("\n=========================================================\n");
}
