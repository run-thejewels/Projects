/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademenet <ademenet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/17 13:47:22 by ademenet          #+#    #+#             */
/*   Updated: 2019/08/30 19:22:27 by kbethany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

t_com		*comnew(t_stack *l, char *s)
{
	t_com	*c;

	if (!(c = (t_com*)malloc(sizeof(t_com))))
		return (NULL);
	c->ct = ft_strdup(s);
	if (!l->cs)
	{
		c->b = NULL;
		l->cs = c;
		l->ce = l->cs;
	}
	else
	{
		c->b = l->ce;
		l->ce->n = c;
		l->ce = c;
	}
	c->n = NULL;
	l->cline_len++;
	return (c);
}

void		rrs(t_stack *l, char a)
{
	if (a == 'a')
	{
		rra(l);
		comnew(l, "rra\n");
	}
	else if (a == 'b')
	{
		rrb(l);
		comnew(l, "rrb\n");
	}
	else if (a == 'v')
		rrv(l);
	else if (a == 'w')
	{
		rrv(l);
		rrb(l);
	}
	else if (a == 's')
	{
		rra(l);
		rrb(l);
		comnew(l, "rrr\n");
	}
}

void		rra(t_stack *l)
{
	int tmp;
	int i;

	tmp = l->va[l->ia - 1];
	i = l->ia - 1;
	while (i > 0)
	{
		l->va[i] = l->va[i - 1];
		i--;
	}
	l->va[0] = tmp;
}

void		rrv(t_stack *l)
{
	int tmp;
	int i;

	tmp = l->vv[l->iv - 1];
	i = l->iv - 1;
	while (i > 0)
	{
		l->vv[i] = l->vv[i - 1];
		i--;
	}
	l->vv[0] = tmp;
}

void		rrb(t_stack *l)
{
	int tmp;
	int i;

	tmp = l->vb[l->ib - 1];
	i = l->ib - 1;
	while (i > 0)
	{
		l->vb[i] = l->vb[i - 1];
		i--;
	}
	l->vb[0] = tmp;
}
