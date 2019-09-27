/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shreders.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbethany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/24 16:08:46 by kbethany          #+#    #+#             */
/*   Updated: 2019/08/24 16:11:06 by kbethany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void		shreder(t_stack *l)
{
	t_com	*leo;

	leo = l->cs;
	while(l->cs->n)
	{
		if ((!ft_strcmp(l->cs->ct, "rra\n") && !ft_strcmp(l->cs->n->ct, "ra\n")) ||
			(!ft_strcmp(l->cs->ct, "ra\n") && !ft_strcmp(l->cs->n->ct, "rra\n")))
		{
			free(l->cs->ct);
			free(l->cs->n->ct);
			l->cs->n->n->b = l->cs->b;
			l->cs->b->n = l->cs->n->n;
		}
		if (!ft_strcmp(l->cs->ct, "rrs\n") && !ft_strcmp(l->cs->n->ct, "ra\n"))
		{
			free(l->cs->ct);
			l->cs->ct = ft_strdup("rrb\n");
			free(l->cs->n->ct);
			l->cs->n->n->b = l->cs;
			l->cs->n = l->cs->n->n;
		}
		if (!ft_strcmp(l->cs->ct, "rrs\n") && !ft_strcmp(l->cs->n->ct, "rb\n"))
		{
			ft_printf("85\n");
			free(l->cs->ct);
			l->cs->ct = ft_strdup("rra\n");
			free(l->cs->n->ct);
			l->cs->n->n->b = l->cs;
			l->cs->n = l->cs->n->n;
		}
		if (!ft_strcmp(l->cs->ct, "rs\n") && !ft_strcmp(l->cs->n->ct, "rra\n"))
		{
			free(l->cs->ct);
			l->cs->ct = ft_strdup("rb\n");
			free(l->cs->n->ct);
			l->cs->n->n->b = l->cs;
			l->cs->n = l->cs->n->n;
		}
		if (!ft_strcmp(l->cs->ct, "rs\n") && !ft_strcmp(l->cs->n->ct, "rrb\n"))
		{
			free(l->cs->ct);
			l->cs->ct = ft_strdup("ra\n");
			free(l->cs->n->ct);
			l->cs->n->n->b = l->cs;
			l->cs->n = l->cs->n->n;
		}
		l->cs = (t_com*)l->cs->n;
	}
	l->cs = leo;
}

void		shreder_plusultra(t_stack *l)
{
	t_com	*raf_tb;
	int		i;

	i = 0;
	raf_tb = l->cs;
	while(l->cs->n)
	{
		if (!ft_strcmp(l->cs->ct, "rra\n") || !ft_strcmp(l->cs->ct, "ra\n"))
			i++;
		l->cs = (t_com*)l->cs->n;
	}
	l->cs = raf_tb;
	while (i)
	{
		shreder(l);
		i--;
	}
}
