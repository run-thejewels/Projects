/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operators_s_ps.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 20:42:20 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/07/21 20:42:22 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../shared_s/push_swap.h"

void sa_ps(t_stacks *stacks, t_flaggs *flags)
{
	if (!stacks->size_a || stacks->size_a == 1)
		return ;
	ft_swap_n_bytes(&((stacks->stack_a)[stacks->size_a - 1]), \
	&((stacks->stack_a)[stacks->size_a - 2]), sizeof(int));
	print_operations(stacks, "sa", flags);
}

void sb_ps(t_stacks *stacks, t_flaggs *flags)
{
	if (!stacks->size_b || stacks->size_b == 1)
		return ;
	ft_swap_n_bytes(&((stacks->stack_b)[stacks->size_b - 1]), \
	&((stacks->stack_b)[stacks->size_b - 2]), sizeof(int));
	print_operations(stacks, "sb", flags);
}

void ss_ps(t_stacks *stacks, t_flaggs *flags)
{
	if (!stacks->size_a || stacks->size_a == 1)
		return ;
	if (stacks->size_a > 1)
	{
		ft_swap_n_bytes(&((stacks->stack_a)[stacks->size_a - 1]), \
		&((stacks->stack_a)[stacks->size_a - 2]), sizeof(int));
	}
	if (stacks->size_b > 1)
	{
		ft_swap_n_bytes(&((stacks->stack_b)[stacks->size_b - 1]), \
		&((stacks->stack_b)[stacks->size_b - 2]), sizeof(int));
	}
	print_operations(stacks, "ss", flags);
}
