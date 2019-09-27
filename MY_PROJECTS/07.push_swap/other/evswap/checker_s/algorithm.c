/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 22:13:36 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/07/20 22:13:38 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../shared_s/push_swap.h"

static void do_operator(t_stacks *stacks, char *oper)
{
	if (ft_strstr(oper, "pa"))
		pa(stacks);
	else if (ft_strstr(oper, "pb"))
		pb(stacks);
	else if (ft_strstr(oper, "ra") && ft_strlen(oper) == 2)
		ra(stacks);
	else if (ft_strstr(oper, "rb") && ft_strlen(oper) == 2)
		rb(stacks);
	else if (ft_strstr(oper, "rr") && ft_strlen(oper) == 2)
		rr(stacks);
	else if (ft_strstr(oper, "rra"))
		rra(stacks);
	else if (ft_strstr(oper, "rrb"))
		rrb(stacks);
	else if (ft_strstr(oper, "rrr"))
		rrr(stacks);
	else if (ft_strstr(oper, "sa"))
		sa(stacks);
	else if (ft_strstr(oper, "sb"))
		sb(stacks);
	else if (ft_strstr(oper, "ss"))
		ss(stacks);
}

static void operators_loop(t_stacks *stacks, t_list *operators)
{
	if (!operators)
		return ;
	while (operators)
	{
		if (operators->content)
			do_operator(stacks, operators->content);
		operators = operators->next;
	}
}

void algorithm(t_stacks *stacks, t_list *operators)
{
	operators_loop(stacks, operators);
	if (is_sorted(stacks->stack_a, stacks->size_a) && !stacks->size_b)
		ft_putstr("OK\n");
	else
		ft_putstr("KO\n");
	ft_lst_free_chain(operators);
}
