/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rymuller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 11:52:58 by rymuller          #+#    #+#             */
/*   Updated: 2019/06/28 15:01:52 by rymuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char		is_read_command_and_sort(t_stack *stack, char *line)
{
	while (get_next_line(0, &line))
	{
		if (is_swap_command(stack, line)
				|| is_push_command(stack, line)
				|| is_rotate_command(stack, line)
				|| is_rev_rotate_command(stack, line))
			free(line);
		else
		{
			write(2, "Error\n", 6);
			free_doubly_list(stack->btm_b);
			exit(EXIT_FAILURE);
		}
	}
	if (stack->size != stack->len_a)
		return (0);
	return (is_sort_stack(stack->btm_b));
}

static void		visual_flags(t_stack *stack, int *argc, char ***argv)
{
	if (!ft_strcmp((*argv)[1], "-vc") || !ft_strcmp((*argv)[1], "-cv"))
	{
		(*argc)--;
		(*argv)++;
		stack->print = 1;
		stack->color = 1;
	}
	else if ((*argc > 2)
			&& ((!ft_strcmp((*argv)[1], "-v") && !ft_strcmp((*argv)[2], "-c"))
			|| (!ft_strcmp((*argv)[1], "-c") && !ft_strcmp((*argv)[2], "-v"))))
	{
		(*argc) -= 2;
		(*argv) += 2;
		stack->print = 1;
		stack->color = 1;
	}
	else if (!ft_strcmp((*argv)[1], "-v"))
	{
		(*argc)--;
		(*argv)++;
		stack->print = 1;
	}
}

int				main(int argc, char **argv)
{
	char			*line;
	t_stack			stack;

	if (argc > 1)
	{
		line = NULL;
		initialize(&stack);
		visual_flags(&stack, &argc, &argv);
		if (!is_placing_argv_stack(&stack, argc, argv))
		{
			write(2, "Error\n", 6);
			return (0);
		}
		if (!is_read_command_and_sort(&stack, line))
		{
			write(1, "KO\n", 3);
			free_doubly_list(stack.btm_b);
			return (0);
		}
		else
			write(1, "OK\n", 3);
		free_doubly_list(stack.btm_b);
	}
	return (0);
}
