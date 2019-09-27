/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rymuller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 16:38:27 by rymuller          #+#    #+#             */
/*   Updated: 2019/06/28 15:01:23 by rymuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	is_rev_rotate_command(t_stack *stack, char *line)
{
	if (!ft_strcmp(line, "rra"))
	{
		rra(stack);
		return (1);
	}
	else if (!ft_strcmp(line, "rrb"))
	{
		rrb(stack);
		return (1);
	}
	else if (!ft_strcmp(line, "rrr"))
	{
		rrr(stack);
		return (1);
	}
	return (0);
}

void	rra(t_stack *stack)
{
	t_doubly_list	*btm_a_buff;

	if (stack->len_a > 1)
	{
		btm_a_buff = stack->btm_a->prev;
		btm_a_buff->next = NULL;
		stack->btm_a->next = stack->top_a;
		stack->btm_a->prev = stack->top_a->prev;
		if (stack->top_a->prev)
			stack->top_a->prev->next = stack->btm_a;
		stack->top_a->prev = stack->btm_a;
		stack->top_a = stack->btm_a;
		stack->btm_a = btm_a_buff;
		if (stack->size == stack->len_a)
			stack->btm_b = stack->top_a;
	}
	if (stack->print)
	{
		if (stack->color && (stack->len_a > 1))
			stack->top_a->color = 1;
		stack->color ? ft_printf(C">>>>> rra\n"C) : ft_printf(N">>>>> rra\n"N);
		print(stack);
	}
}

void	rrb(t_stack *stack)
{
	t_doubly_list	*btm_b_buff;

	if (stack->size - stack->len_a > 1)
	{
		btm_b_buff = stack->btm_b->next;
		btm_b_buff->prev = NULL;
		stack->btm_b->next = stack->top_b->next;
		stack->btm_b->prev = stack->top_b;
		if (stack->top_b->next)
			stack->top_b->next->prev = stack->btm_b;
		stack->top_b->next = stack->btm_b;
		stack->top_b = stack->btm_b;
		stack->btm_b = btm_b_buff;
		if (stack->len_a == 0)
			stack->btm_a = stack->top_b;
	}
	if (stack->print)
	{
		if (stack->color && (stack->size - stack->len_a > 1))
			stack->top_b->color = 1;
		stack->color ? ft_printf(C">>>>> rrb\n"C) : ft_printf(N">>>>> rrb\n"N);
		print(stack);
	}
}

void	rrr(t_stack *stack)
{
	char	flag;

	flag = stack->print;
	if (flag)
		stack->print = 0;
	if (flag)
		stack->print = 1;
	rra(stack);
	rrb(stack);
	if (stack->print)
	{
		if (stack->color && (stack->len_a > 1))
			stack->top_a->color = 1;
		if (stack->color && (stack->size - stack->len_a > 1))
			stack->top_b->color = 1;
		if (stack->color)
			ft_printf(C">>>>> rrr\n"C);
		else
			ft_printf(N">>>>> rrr\n"N);
		print(stack);
	}
}
