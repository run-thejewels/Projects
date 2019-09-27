/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbethany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 21:55:06 by kbethany          #+#    #+#             */
/*   Updated: 2019/08/30 21:56:24 by kbethany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

void	rr(t_stack *l, char a)
{
	if (a == 'a')
	{
		ra(l);
		comnew(l, "ra\n");
	}
	else if (a == 'v')
		rv(l);
	else if (a == 'w')
	{
		rv(l);
		rb(l);
	}
	else if (a == 'b')
	{
		rb(l);
		comnew(l, "rb\n");
	}
	if (a == 's')
	{
		ra(l);
		rb(l);
		comnew(l, "rr\n");
	}
}

void	ra(t_stack *l)
{
	int	tmp;
	int	i;

	i = 0;
	tmp = l->va[i];
	while (i < l->ia - 1)
	{
		l->va[i] = l->va[i + 1];
		i++;
	}
	l->va[i] = tmp;
}

void	rv(t_stack *l)
{
	int	tmp;
	int	i;

	i = 0;
	tmp = l->vv[i];
	while (i < l->iv - 1)
	{
		l->vv[i] = l->vv[i + 1];
		i++;
	}
	l->vv[i] = tmp;
}

void	rb(t_stack *l)
{
	int	tmp;
	int	i;

	i = 0;
	tmp = l->vb[i];
	while (i < l->ib - 1)
	{
		l->vb[i] = l->vb[i + 1];
		i++;
	}
	l->vb[i] = tmp;
}
