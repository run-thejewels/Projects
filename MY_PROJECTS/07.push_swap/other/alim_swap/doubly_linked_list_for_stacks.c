/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doubly_linked_list_for_stacks.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rymuller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 15:49:52 by rymuller          #+#    #+#             */
/*   Updated: 2019/06/30 15:49:57 by rymuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void					initialize(t_stack *stack)
{
	stack->len_a = 0;
	stack->top_a = NULL;
	stack->btm_a = NULL;
	stack->top_b = NULL;
	stack->btm_b = NULL;
	stack->size = 0;
	stack->len_less_pvt = 0;
	stack->len_more_pvt = 0;
	stack->len_pvts_b = NULL;
	stack->command_list = NULL;
	stack->print = 0;
	stack->color = 0;
}

t_doubly_list			*ft_list_new(int value)
{
	t_doubly_list	*list;

	if (!(list = (t_doubly_list *)malloc(sizeof(t_doubly_list))))
		return (NULL);
	list->value = value;
	list->color = 0;
	list->prev = NULL;
	list->next = NULL;
	return (list);
}

void					free_doubly_list(t_doubly_list *doubly_list)
{
	t_doubly_list	*buffer;

	if (doubly_list)
	{
		buffer = doubly_list;
		while (buffer->next)
		{
			buffer = buffer->next;
			free(buffer->prev);
		}
		free(buffer);
	}
}

t_doubly_list			*ft_list_push_back(t_stack *stack, int value)
{
	t_doubly_list	*buffer;

	if (stack->btm_b)
	{
		buffer = stack->btm_b;
		while (buffer->next)
			buffer = buffer->next;
		if (!(buffer->next = ft_list_new(value)))
		{
			free_doubly_list(stack->btm_b);
			exit(EXIT_FAILURE);
		}
		stack->btm_a = buffer->next;
		buffer->next->prev = buffer;
		return (stack->btm_b);
	}
	else
	{
		if (!(buffer = ft_list_new(value)))
			exit(EXIT_FAILURE);
		return (buffer);
	}
}
