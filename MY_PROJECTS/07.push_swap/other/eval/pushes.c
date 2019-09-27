/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbethany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 17:01:50 by kbethany          #+#    #+#             */
/*   Updated: 2019/08/30 18:32:23 by kbethany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

void		comander(t_stack *l, char *str)
{
	if (!ft_strcmp(str, "pa\n"))
		pv(l);
	if (!ft_strcmp(str, "pb\n"))
		pvb(l);
	if (!ft_strcmp(str, "ra\n"))
		rv(l);
	if (!ft_strcmp(str, "rb\n"))
		rr(l, 'b');
	if (!ft_strcmp(str, "rr\n"))
		rr(l, 'w');
	if (!ft_strcmp(str, "sa\n"))
		sv(l);
	if (!ft_strcmp(str, "sb\n"))
		ss(l, 'b');
	if (!ft_strcmp(str, "ss\n"))
		ss(l, 's');
	if (!ft_strcmp(str, "rra\n"))
		rrs(l, 'v');
	if (!ft_strcmp(str, "rrb\n"))
		rrs(l, 'b');
	if (!ft_strcmp(str, "rrr\n"))
		rrs(l, 'w');
}

void		display(t_stack *l)
{
	int	i;

	i = 0;
	ft_printf("\n=========================================================\n");
	ft_printf("Elements: %d\nMax: %d\nMin: %d\n\nA: ", l->iv, l->max, l->min);
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

t_stack		*lstnew(void)
{
	t_stack		*l;

	if (!(l = (t_stack*)malloc(sizeof(t_stack))))
		return (NULL);
	if (l != NULL)
	{
		l->va[0] = 0;
		l->vv[0] = 0;
		l->vb[0] = 0;
		l->ia = 0;
		l->ib = 0;
		l->iv = 0;
		l->max = 0;
		l->min = 0;
		l->in = 0;
		l->com_a[0] = 0;
		l->com_b[0] = 0;
		l->ce = NULL;
		l->cs = NULL;
		l->cline_len = 0;
		l->v = 0;
	}
	return (l);
}
