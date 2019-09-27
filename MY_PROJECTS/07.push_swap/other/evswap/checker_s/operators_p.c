/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operators_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 20:57:53 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/07/21 20:57:55 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../shared_s/push_swap.h"

void pa(t_stacks *stacks)
{
	if (!stacks->size_b)
		return ;
	stacks->stack_a[stacks->size_a] = stacks->stack_b[stacks->size_b - 1];
	stacks->size_a++;
	stacks->size_b--;
}

void pb(t_stacks *stacks)
{
	if (!stacks->size_a)
		return ;
	stacks->stack_b[stacks->size_b] = stacks->stack_a[stacks->size_a - 1];
	stacks->size_b++;
	stacks->size_a--;
}
