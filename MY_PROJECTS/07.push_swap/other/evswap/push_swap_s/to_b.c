/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_b.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 21:31:34 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/07/22 21:31:37 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../shared_s/push_swap.h"

void to_b(t_stacks *stacks, t_flaggs *flags)
{
	while (stacks->size_a > 3)
	{
		if ((stacks->stack_a)[stacks->size_a - 1] == stacks->max \
		|| (stacks->stack_a)[stacks->size_a - 1] == stacks->min)
			ra_ps(stacks, flags);
		else
			pb_ps(stacks, flags);
	}
	sorting_three(stacks->stack_a, stacks->size_a, stacks, flags);
}
