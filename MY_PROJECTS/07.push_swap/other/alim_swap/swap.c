/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rymuller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 16:29:32 by rymuller          #+#    #+#             */
/*   Updated: 2019/06/28 14:49:52 by rymuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	is_swap_command(t_stack *stack, char *line)
{
	if (!ft_strcmp(line, "sa"))
	{
		sa(stack);
		return (1);
	}
	else if (!ft_strcmp(line, "sb"))
	{
		sb(stack);
		return (1);
	}
	else if (!ft_strcmp(line, "ss"))
	{
		ss(stack);
		return (1);
	}
	return (0);
}

void	sa(t_stack *stack)
{
	int		value;

	if (stack->len_a > 1)
	{
		value = stack->top_a->value;
		stack->top_a->value = stack->top_a->next->value;
		stack->top_a->next->value = value;
	}
	if (stack->print)
	{
		if (stack->color && (stack->len_a > 1))
			stack->top_a->next->color = 1;
		if (stack->color)
			ft_printf(C">>>>>> sa\n"C);
		else
			ft_printf(N">>>>>> sa\n"N);
		print(stack);
	}
}

void	sb(t_stack *stack)
{
	int		value;

	if (stack->size - stack->len_a > 1)
	{
		value = stack->top_b->value;
		stack->top_b->value = stack->top_b->prev->value;
		stack->top_b->prev->value = value;
	}
	if (stack->print)
	{
		if (stack->color && (stack->size - stack->len_a > 1))
			stack->top_b->prev->color = 1;
		if (stack->color)
			ft_printf(C">>>>>> sb\n"C);
		else
			ft_printf(N">>>>>> sb\n"N);
		print(stack);
	}
}

void	ss(t_stack *stack)
{
	char	flag;

	flag = stack->print;
	if (flag)
		stack->print = 0;
	sa(stack);
	sb(stack);
	if (flag)
		stack->print = 1;
	if (stack->print)
	{
		if (stack->color && (stack->len_a > 1))
			stack->top_a->next->color = 1;
		if (stack->color && (stack->size - stack->len_a > 1))
			stack->top_b->prev->color = 1;
		if (stack->color)
			ft_printf(C">>>>>> ss\n"C);
		else
			ft_printf(N">>>>>> ss\n"N);
		print(stack);
	}
}
