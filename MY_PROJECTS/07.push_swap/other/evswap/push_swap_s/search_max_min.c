/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_max_min.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 21:32:18 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/07/22 21:32:20 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../shared_s/push_swap.h"

static void search_max(t_stacks *stacks)
{
	int result;
	size_t index;

	result = (stacks->stack_a)[0];
	index = 1;
	while (index < stacks->size_a)
	{
		if ((stacks->stack_a)[index] > result)
			result = (stacks->stack_a)[index];
		index++;
	}
	stacks->max = result;
}

static void search_min(t_stacks *stacks)
{
	int result;
	size_t index;

	result = (stacks->stack_a)[0];
	index = 1;
	while (index < stacks->size_a)
	{
		if ((stacks->stack_a)[index] < result)
			result = (stacks->stack_a)[index];
		index++;
	}
	stacks->min = result;
}

void search_max_min(t_stacks *stacks)
{
	search_max(stacks);
	search_min(stacks);
}
