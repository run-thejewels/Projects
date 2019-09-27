/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_argv_and_placing_stack.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rymuller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 14:15:43 by rymuller          #+#    #+#             */
/*   Updated: 2019/06/22 15:43:05 by rymuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char			is_sort_stack(t_doubly_list *top)
{
	while (top->next)
	{
		if (top->value > top->next->value)
			return (0);
		top = top->next;
	}
	return (1);
}

static char		is_not_digit_space(t_stack *stack, int argc, char **argv)
{
	int				i;
	int				j;

	i = 0;
	while (++i < argc)
	{
		j = -1;
		while (argv[i][++j])
		{
			if ((argv[i][j] == '-' || argv[i][j] == '+')
					&& !ft_isdigit(argv[i][j + 1]))
				return (1);
			if ((argv[i][j] != ' ' && !ft_isdigit(argv[i][j])
					&& argv[i][j] != '+' && argv[i][j] != '-'))
				return (1);
			else if (ft_isdigit(argv[i][j])
					&& (argv[i][j + 1] == ' ' || argv[i][j + 1] == '\0'))
				stack->size++;
		}
	}
	return (stack->size == 0 ? 1 : 0);
}

static char		fill_stack(t_stack *stack, int argc, char **argv)
{
	int				i;
	long int		value;
	char			**str;

	i = 0;
	while (++i < argc)
	{
		str = argv + i;
		while (**str)
		{
			while (ft_isspace(**str))
				(*str)++;
			if (!**str)
				break ;
			else
			{
				if ((value = ft_atoi_shift(str)) > MAX_INT || value < MIN_INT)
					return (0);
				stack->btm_b = ft_list_push_back(stack, value);
			}
		}
	}
	return (1);
}

static char		is_dupl_in_stack(t_stack *stack)
{
	t_doubly_list *buffer1;
	t_doubly_list *buffer2;

	buffer1 = stack->btm_b;
	while (buffer1->next)
	{
		buffer2 = buffer1->next;
		while (buffer2)
		{
			if (buffer1->value == buffer2->value)
				return (1);
			buffer2 = buffer2->next;
		}
		buffer1 = buffer1->next;
	}
	stack->len_a = stack->size;
	stack->top_a = stack->btm_b;
	return (0);
}

char			is_placing_argv_stack(t_stack *stack, int argc, char **argv)
{
	if (is_not_digit_space(stack, argc, argv))
		return (0);
	if (!fill_stack(stack, argc, argv))
	{
		free_doubly_list(stack->btm_b);
		return (0);
	}
	if (is_dupl_in_stack(stack))
	{
		free_doubly_list(stack->btm_b);
		return (0);
	}
	return (1);
}
