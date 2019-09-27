/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimizing_sort_algorithm.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rymuller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 14:42:38 by rymuller          #+#    #+#             */
/*   Updated: 2019/06/28 14:42:49 by rymuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	delete_command(t_stack *stack, t_command_list *command)
{
	t_command_list	*prev_comm;
	t_command_list	*next_comm;

	if (command)
	{
		prev_comm = command->prev;
		next_comm = command->next;
		if (prev_comm)
			prev_comm->next = next_comm;
		else
			stack->command_list = next_comm;
		if (next_comm)
			next_comm->prev = prev_comm;
		free(command);
	}
}

void		optimizing_commands_list(t_stack *stack)
{
	t_command_list	*buffer;

	if (stack->command_list)
	{
		buffer = stack->command_list;
		while (buffer->next && buffer->next->next)
		{
			if (!ft_strcmp(buffer->next->command, "rra\n")
				&& !ft_strcmp(buffer->next->next->command, "ra\n"))
			{
				delete_command(stack, buffer->next);
				delete_command(stack, buffer->next);
				buffer = buffer->prev;
			}
			else if (!ft_strcmp(buffer->next->command, "rrb\n")
				&& !ft_strcmp(buffer->next->next->command, "rb\n"))
			{
				delete_command(stack, buffer->next);
				delete_command(stack, buffer->next);
				buffer = buffer->prev;
			}
			else
				buffer = buffer->next;
		}
	}
}
