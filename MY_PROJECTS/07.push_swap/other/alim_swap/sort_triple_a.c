/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_triple_a.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rymuller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 14:43:06 by rymuller          #+#    #+#             */
/*   Updated: 2019/06/28 16:40:28 by rymuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		sort_double(t_stack *stack)
{
	if ((stack->len_pvts_b != NULL && stack->len_pvts_b->value > 1)
		&& (stack->top_a->value > stack->top_a->next->value)
		&& (stack->top_b->value < stack->top_b->next->value))
	{
		SS(stack);
	}
	else if (stack->top_a->value > stack->top_a->next->value)
	{
		SA(stack);
	}
}

static void		sort_triple_without_sorted_a(t_stack *stack, int *a, int *b,
		int *c)
{
	if (*c > *a && *b > *a && *b > *c)
	{
		RA(stack);
		SA(stack);
		RRA(stack);
	}
	else if (*a > *b && *a > *c && *b > *c)
	{
		SA(stack);
		RRA(stack);
	}
	else if (*c > *a && *c > *b && *a > *b)
	{
		SA(stack);
	}
	else if (*b > *a && *b > *c && *a > *c)
	{
		RRA(stack);
	}
	else if (*a > *c && *a > *b && *c > *b)
	{
		RA(stack);
	}
}

static void		sort_triple_with_sorted_a_1(t_stack *stack, int *a, int *b,
		int *c)
{
	if (*c > *a && *b > *a && *b > *c)
	{
		PB(stack);
		SA(stack);
		PA(stack);
	}
	else if (*a > *b && *a > *c && *b > *c)
	{
		RA(stack);
		SA(stack);
		PB(stack);
		PB(stack);
		RRA(stack);
		PA(stack);
		PA(stack);
	}
	else if (*c > *a && *c > *b && *a > *b)
	{
		SA(stack);
	}
}

static void		sort_triple_with_sorted_a(t_stack *stack, int *a, int *b,
		int *c)
{
	if ((*c > *a && *b > *a && *b > *c)
		|| (*a > *b && *a > *c && *b > *c)
		|| (*c > *a && *c > *b && *a > *b))
		sort_triple_with_sorted_a_1(stack, a, b, c);
	else if (*b > *a && *b > *c && *a > *c)
	{
		RA(stack);
		RA(stack);
		PB(stack);
		RRA(stack);
		RRA(stack);
		PA(stack);
	}
	else if (*a > *c && *a > *b && *c > *b)
	{
		PB(stack);
		RA(stack);
		RA(stack);
		PA(stack);
		RRA(stack);
		RRA(stack);
	}
}

void			sort_triple_a(t_stack *stack)
{
	int			a;
	int			b;
	int			c;

	if ((stack->len_a == 2 || stack->len_more_pvt == 2))
		sort_double(stack);
	else if (stack->len_a >= 3)
	{
		a = stack->top_a->value;
		b = stack->top_a->next->value;
		c = stack->top_a->next->next->value;
		if (stack->len_a == 3)
			sort_triple_without_sorted_a(stack, &a, &b, &c);
		else
			sort_triple_with_sorted_a(stack, &a, &b, &c);
	}
}
