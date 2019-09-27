/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shreder.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbethany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 21:23:26 by kbethany          #+#    #+#             */
/*   Updated: 2019/09/01 14:20:20 by kbethany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

static void	shreder_helper(t_stack *l)
{
	if ((!ft_strcmp(l->ce->ct, "rra\n") && !ft_strcmp(l->ce->n->ct, "ra\n")) ||
		(!ft_strcmp(l->ce->ct, "ra\n") && !ft_strcmp(l->ce->n->ct, "rra\n")))
	{
		free(l->ce->ct);
		free(l->ce->n->ct);
		l->ce->n->n->b = l->ce->b;
		l->ce->b->n = l->ce->n->n;
		l->cline_len = l->cline_len - 2;
	}
	if (!ft_strcmp(l->ce->ct, "rrs\n") && !ft_strcmp(l->ce->n->ct, "ra\n"))
	{
		free(l->ce->ct);
		l->ce->ct = ft_strdup("rrb\n");
		free(l->ce->n->ct);
		l->ce->n->n->b = l->ce;
		l->ce->n = l->ce->n->n;
		l->cline_len--;
	}
}

static void	shreder_helper_too(t_stack *l)
{
	if (!ft_strcmp(l->ce->ct, "rrs\n") && !ft_strcmp(l->ce->n->ct, "rb\n"))
	{
		free(l->ce->ct);
		l->ce->ct = ft_strdup("rra\n");
		free(l->ce->n->ct);
		l->ce->n->n->b = l->ce;
		l->ce->n = l->ce->n->n;
		l->cline_len--;
	}
	if (!ft_strcmp(l->ce->ct, "rs\n") && !ft_strcmp(l->ce->n->ct, "rra\n"))
	{
		free(l->ce->ct);
		l->ce->ct = ft_strdup("rb\n");
		free(l->ce->n->ct);
		l->ce->n->n->b = l->ce;
		l->ce->n = l->ce->n->n;
		l->cline_len--;
	}
}

void		shreder(t_stack *l)
{
	l->ce = l->cs;
	while (l->ce->n)
	{
		shreder_helper(l);
		shreder_helper_too(l);
		if (!ft_strcmp(l->ce->ct, "rs\n") && !ft_strcmp(l->ce->n->ct, "rrb\n"))
		{
			free(l->ce->ct);
			l->ce->ct = ft_strdup("ra\n");
			free(l->ce->n->ct);
			l->ce->n->n->b = l->ce;
			l->ce->n = l->ce->n->n;
			l->cline_len--;
		}
		if (!ft_strcmp(l->ce->ct, "pb\n") && !ft_strcmp(l->ce->n->ct, "pa\n"))
		{
			free(l->ce->ct);
			free(l->ce->n->ct);
			l->ce->n->n->b = l->ce->b;
			l->ce->b->n = l->ce->n->n;
			l->cline_len = l->cline_len - 2;
		}
		l->ce = (t_com*)l->ce->n;
	}
}

void		shreder_plusultra(t_stack *l)
{
	int	i;

	i = 0;
	l->ce = l->cs;
	while (l->ce->n)
	{
		if (!ft_strcmp(l->ce->ct, "rra\n") || !ft_strcmp(l->ce->ct, "ra\n"))
			i++;
		l->ce = (t_com*)l->ce->n;
	}
	while (i)
	{
		shreder(l);
		i--;
	}
}
