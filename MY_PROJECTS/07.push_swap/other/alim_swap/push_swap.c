/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rymuller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 14:09:35 by rymuller          #+#    #+#             */
/*   Updated: 2019/06/28 15:11:27 by rymuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		find_pvt_leave_less_four_elem_stack_a(t_stack *stack)
{
	int			pvt;

	while (stack->len_a > 3)
	{
		stack->len_less_pvt = 0;
		pvt = find_pvt_stack_a(stack, stack->len_a);
		while (is_less_pvt_stack_a(stack, stack->len_a, pvt))
		{
			if (stack->top_a->value < pvt)
			{
				PB(stack);
				stack->len_less_pvt++;
			}
			else
			{
				RA(stack);
			}
		}
		stack->len_pvts_b = ft_list_push_forw(stack);
	}
}

static void		find_pvt_more_elem_push_a(t_stack *stack)
{
	size_t			len;
	int				pvt;
	size_t			rb_count;

	rb_count = 0;
	stack->len_more_pvt = 0;
	len = stack->len_pvts_b->value;
	pvt = find_pvt_stack_b(stack, len);
	while (is_more_pvt_stack_b(stack, len, pvt))
	{
		if (stack->top_b->value > pvt)
		{
			PA(stack);
			stack->len_more_pvt++;
		}
		else
		{
			RB(stack);
			rb_count++;
		}
		len--;
	}
	DEF_STATE_B(stack, rb_count);
	stack->len_pvts_b->value -= stack->len_more_pvt;
}

static void		find_pvt_less_elem_push_b(t_stack *stack)
{
	size_t			len;
	int				pvt;
	size_t			ra_count;

	ra_count = 0;
	stack->len_less_pvt = 0;
	len = stack->len_more_pvt;
	pvt = find_pvt_stack_a(stack, len);
	while (is_less_pvt_stack_a(stack, len, pvt))
	{
		if (stack->top_a->value < pvt)
		{
			PB(stack);
			stack->len_less_pvt++;
		}
		else
		{
			RA(stack);
			ra_count++;
		}
		len--;
	}
	DEF_STATE_A(stack, ra_count);
	stack->len_more_pvt -= stack->len_less_pvt;
	stack->len_pvts_b = ft_list_push_forw(stack);
}

static void		sort(t_stack *stack)
{
	find_pvt_leave_less_four_elem_stack_a(stack);
	sort_triple_a(stack);
	while (stack->size != stack->len_a)
	{
		if (stack->len_pvts_b->value < 3)
		{
			stack->len_more_pvt = 0;
			while (stack->len_pvts_b->value)
			{
				PA(stack);
				stack->len_more_pvt++;
				stack->len_pvts_b->value--;
			}
			stack->len_pvts_b = del_list_forw(stack);
			sort_triple_a(stack);
		}
		else
		{
			find_pvt_more_elem_push_a(stack);
			while (stack->len_more_pvt > 3)
				find_pvt_less_elem_push_b(stack);
			sort_triple_a(stack);
		}
	}
}

int				main(int argc, char **argv)
{
	t_stack			stack;

	if (argc > 1)
	{
		initialize(&stack);
		if (!is_placing_argv_stack(&stack, argc, argv))
		{
			write(2, "Error\n", 6);
			return (0);
		}
		if (!is_sort_stack(stack.top_a))
		{
			sort(&stack);
			optimizing_commands_list(&stack);
			print_commands(&stack);
		}
		free_doubly_list(stack.btm_b);
		free_doubly_list(stack.len_pvts_b);
		free_command_list(stack.command_list);
	}
	return (0);
}
