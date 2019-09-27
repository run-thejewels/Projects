/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fastest_cowboy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 23:33:15 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/07/22 23:33:17 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../shared_s/push_swap.h"

int fastest_cowboy(t_stacks *stacks)
{
	size_t temp;
	size_t result_size;
	size_t index;
	size_t result_index;

	index = 1;

	result_size = how_many_steps_to_get_out(0, stacks->size_b) + how_many_steps_to_get_out(is_sorted_shift_in_mind_ps(stacks->stack_a, stacks->size_a, \
	(stacks->stack_b)[0]), stacks->size_a);
	result_index = 0;
	while (index < stacks->size_b)
	{
		temp = how_many_steps_to_get_out(index, stacks->size_b);
		temp += how_many_steps_to_get_out(is_sorted_shift_in_mind_ps(stacks->stack_a, stacks->size_a, (stacks->stack_b)[index]), stacks->size_a);
		if (temp < result_size)
		{
			result_size = temp;
			result_index = index;
		}
		index++;
	}
	return ((stacks->stack_b)[result_index]);
}
