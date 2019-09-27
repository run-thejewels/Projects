/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operators_r.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 21:32:56 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/07/22 21:32:58 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../shared_s/push_swap.h"

static void ints_shift_right(int *ints, size_t size)
{
	size_t index;

	index = size - 1;
	while (index)
	{
		ints[index] = ints[index - 1];
		index--;
	}
}

void ra(t_stacks *stacks)
{
	int temp;

	if (stacks->size_a <= 1)
		return ;
	temp = (stacks->stack_a)[stacks->size_a - 1];
	ints_shift_right(stacks->stack_a, stacks->size_a);
	(stacks->stack_a)[0] = temp;
}

void rb(t_stacks *stacks)
{
	int temp;

	if (stacks->size_b <= 1)
		return ;
	temp = (stacks->stack_b)[stacks->size_b - 1];
	ints_shift_right(stacks->stack_b, stacks->size_b);
	(stacks->stack_b)[0] = temp;
}

void rr(t_stacks *stacks)
{
	int temp;

	if (stacks->size_b > 1)
	{
		temp = (stacks->stack_b)[stacks->size_b - 1];
		ints_shift_right(stacks->stack_b, stacks->size_b);
		(stacks->stack_b)[0] = temp;
	}
	if (stacks->size_a > 1)
	{
		temp = (stacks->stack_a)[stacks->size_a - 1];
		ints_shift_right(stacks->stack_a, stacks->size_a);
		(stacks->stack_a)[0] = temp;
	}
}
