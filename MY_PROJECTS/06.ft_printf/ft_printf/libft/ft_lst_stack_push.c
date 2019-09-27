/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_stack_push.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 22:32:55 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/04/22 23:11:13 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_lst_stack_push(size_t channel, \
	void *content, size_t content_size)
{
	t_list	*stack;
	t_list	*new;

	if (!(stack = ft_lst_stack_new_stack(channel)))
		return (0);
	if (!(new = (t_list *)ft_lstnew(content, content_size)))
		return (0);
	ft_lstadd((t_list **)(&(stack->content)), new);
	return (1);
}
