/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operators_p_ps.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 20:57:53 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/07/21 20:57:55 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../shared_s/push_swap.h"

void pa_ps(t_stacks *stacks, t_flaggs *flags)
{
	if (!stacks->size_b)
		return ;
	stacks->stack_a[stacks->size_a] = stacks->stack_b[stacks->size_b - 1];
	stacks->size_a++;
	stacks->size_b--;
	print_operations(stacks, "pa", flags);
}

void pb_ps(t_stacks *stacks, t_flaggs *flags)
{
	if (!stacks->size_a)
		return ;
	stacks->stack_b[stacks->size_b] = stacks->stack_a[stacks->size_a - 1];
	stacks->size_b++;
	stacks->size_a--;
	print_operations(stacks, "pb", flags);
}
