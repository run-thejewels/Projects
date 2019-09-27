/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_a.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 21:35:07 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/07/22 21:35:09 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../shared_s/push_swap.h"

static void to_depth(t_stacks *stacks, int fastest, t_flaggs *flags)
{
	size_t mind;
	size_t steps;
	int up;

	mind = is_sorted_shift_in_mind_ps(stacks->stack_a, stacks->size_a, fastest);
	steps = how_many_steps_to_get_out(mind, stacks->size_a);
	up = do_up(mind, stacks->size_a);
	while (steps)
	{
		if (up)
			rra_ps(stacks, flags);
		else
			ra_ps(stacks, flags);
		steps--;
	}
}

static void to_surface(t_stacks *stacks, int fastest, t_flaggs *flags)
{
	size_t index_fastest;
	int up;

	index_fastest = get_index(stacks->stack_b, stacks->size_b, fastest);
	up = do_up(index_fastest, stacks->size_b);
	while ((stacks->stack_b)[stacks->size_b - 1] != fastest)
	{
		if (up)
			rb_ps(stacks, flags);
		else
			rrb_ps(stacks, flags);
	}
}

void to_a(t_stacks *stacks, t_flaggs *flags)
{
	int fastest;

	while (stacks->size_b)
	{
		fastest = fastest_cowboy(stacks);
		to_surface(stacks, fastest, flags);
		to_depth(stacks, fastest, flags);
		pa_ps(stacks, flags);
	}
}
