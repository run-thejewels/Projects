/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 20:44:54 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/07/21 20:44:56 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../shared_s/push_swap.h"

static void put_to_list(t_stacks *stacks, char *str)
{
	ft_lstadd(&(stacks->commands), ft_lstnew_no_copy(str, ft_strlen(str)));
}

static void print_stack(t_stacks *stacks, int *ints, size_t size)
{
	size_t index;

	index = 0;
	while (index < size)
	{
		put_to_list(stacks, ft_itoa(ints[index]));
		put_to_list(stacks, ft_strdup(" "));
		index++;
	}
	put_to_list(stacks, ft_strdup("\n"));
}

void print_operations(t_stacks *stacks, char *operation, t_flaggs *flags)
{
	if (!flags->print)
	{
		put_to_list(stacks, ft_strdup(operation));
		put_to_list(stacks, ft_strdup("\n"));
	}
	else
	{
		put_to_list(stacks, ft_strdup(operation));
		put_to_list(stacks, ft_strdup(":\nStack A: "));
		print_stack(stacks, stacks->stack_a, stacks->size_a);
		put_to_list(stacks, ft_strdup("Stack B: "));
		print_stack(stacks, stacks->stack_b, stacks->size_b);
		put_to_list(stacks, ft_strdup("______________________\n"));
	}
}

void print_begin(t_stacks *stacks, t_flaggs *flags)
{
	if (flags->print)
	{
		put_to_list(stacks, ft_strdup("______________________\n"));
		put_to_list(stacks, ft_strdup("Begin! "));
		put_to_list(stacks, ft_itoa((int)stacks->size_a));
		put_to_list(stacks, ft_strdup(" elements.\n\nStack A: "));
		print_stack(stacks, stacks->stack_a, stacks->size_a);
		put_to_list(stacks, ft_strdup("Stack B: "));
		print_stack(stacks, stacks->stack_b, stacks->size_b);
		put_to_list(stacks, ft_strdup("______________________\n"));
	}
}

void print_final(t_stacks *stacks)
{
	ft_lst_putstr_free(ft_lst_turn(stacks->commands));
}
