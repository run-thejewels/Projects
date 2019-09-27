/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pivots_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rymuller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/22 15:44:43 by rymuller          #+#    #+#             */
/*   Updated: 2019/06/22 15:44:47 by rymuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			find_pvt_stack_a(t_stack *stack, int len)
{
	int				i;
	t_doubly_list	*top;
	int				arr[len];

	if (len > 1)
	{
		i = -1;
		top = stack->top_a;
		while (++i < len)
		{
			arr[i] = top->value;
			top = top->next;
		}
		quicksort(arr, 0, len - 1, 1);
		return (arr[len >> 1]);
	}
	return (stack->top_a->value);
}

int			find_pvt_stack_b(t_stack *stack, int len)
{
	int				i;
	t_doubly_list	*top;
	int				arr[len];

	if (len > 1)
	{
		i = -1;
		top = stack->top_b;
		while (++i < len)
		{
			arr[i] = top->value;
			top = top->prev;
		}
		quicksort(arr, 0, len - 1, 0);
		return (arr[len >> 1]);
	}
	return (stack->top_b->value);
}

char		is_less_pvt_stack_a(t_stack *stack, int len, int pvt)
{
	int				i;
	t_doubly_list	*buff;

	i = -1;
	buff = stack->top_a;
	while (++i < len)
	{
		if (buff->value < pvt)
			return (1);
		buff = buff->next;
	}
	return (0);
}

char		is_more_pvt_stack_b(t_stack *stack, int len, int pvt)
{
	int				i;
	t_doubly_list	*buff;

	i = -1;
	buff = stack->top_b;
	while (++i < len)
	{
		if (buff->value > pvt)
			return (1);
		buff = buff->prev;
	}
	return (0);
}
