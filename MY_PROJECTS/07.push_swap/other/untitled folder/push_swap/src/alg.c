/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbethany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 18:13:49 by kbethany          #+#    #+#             */
/*   Updated: 2019/08/24 16:01:01 by kbethany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_tribus(t_stack* l)
{
	if (l->va[2] < l->va[1] && l->va[2] > l->va[0])
	{
		ss(l, 'a');
		rs(l, 'a');
	}
	else if (l->va[2] > l->va[1] && l->va[2] < l->va[0])
		rs(l, 'a');
	else if (l->va[0] > l->va[1] && l->va[0] < l->va[2])
		ss(l, 'a');
	else if (l->va[0] > l->va[2] && l->va[0] < l->va[1])
		rrs(l, 'a');
	else if (l->va[1] < l->va[0] && l->va[1] > l->va[2])
	{
		ss(l, 'a');
		rrs(l, 'a');
	}
}

int		ideal(t_stack* l)
{
	int	i;

	i = 0;
	while (i < l->ia)
	{
		if (l->va[i] != l->max && l->va[i] > l->va[i + 1])
			return (0);
		if (i == l->ia - 1 && l->va[i] == l->max && l->va[0] != l->min)
			return (0);
		if (i < l->ia - 1 && l->va[i] == l->max && l->va[i + 1] != l->min)
			return (0);
		i++;
	}
	return (1);
}

void	alg(t_stack* l)
{
	int i;

	i = l->ia / 2;
	while (!ideal(l) && (l->va[0] == l->min && l->va[l->ia - 1] == l->max))
	{
		if (l->va[0] > l->va[1] && l->va[0] != l->min && l->va[0] != l->max)
			pb(l);
		else
			rs(l, 'a');
	}
	if (l->ia < 4)
		sort_tribus(l);
	while (l->ib)
	{
		l->com_a = 0;
		l->com_b = 0;
		l->int_a = 0;
		l->int_b = 0;
		l->in = 0;
		sort_b(l);
	}
	shreder_plusultra(l);
}
