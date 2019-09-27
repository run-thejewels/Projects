/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doubly_linked_list_for_sort_command.c              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rymuller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/22 13:59:40 by rymuller          #+#    #+#             */
/*   Updated: 2019/06/28 15:17:17 by rymuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_command_list	*ft_new_command(char *command)
{
	t_command_list		*list;

	if (!(list = (t_command_list *)malloc(sizeof(t_command_list))))
		return (NULL);
	list->command = command;
	list->prev = NULL;
	list->next = NULL;
	return (list);
}

t_command_list			*comm_list(t_stack *stack, char *command)
{
	t_command_list		*buffer;

	if (stack->command_list)
	{
		buffer = stack->command_list;
		while (buffer->next)
			buffer = buffer->next;
		if (!(buffer->next = ft_new_command(command)))
		{
			free_command_list(stack->command_list);
			exit(EXIT_FAILURE);
		}
		buffer->next->prev = buffer;
		return (stack->command_list);
	}
	else
	{
		if (!(buffer = ft_new_command(command)))
			exit(EXIT_FAILURE);
		return (buffer);
	}
}

void					free_command_list(t_command_list *command_list)
{
	t_command_list		*buffer;

	if (command_list)
	{
		buffer = command_list;
		while (buffer->next)
		{
			buffer = buffer->next;
			free(buffer->prev);
		}
		free(buffer);
	}
}

void					print_commands(t_stack *stack)
{
	t_command_list		*buffer;

	if (stack->command_list)
	{
		buffer = stack->command_list;
		while (buffer)
		{
			ft_printf(buffer->command);
			buffer = buffer->next;
		}
	}
}

int						iter_count(t_stack *stack)
{
	t_command_list		*buffer;
	int					iter_count;

	iter_count = 0;
	if (stack->command_list)
	{
		buffer = stack->command_list;
		while (buffer)
		{
			iter_count++;
			buffer = buffer->next;
		}
	}
	return (iter_count);
}
