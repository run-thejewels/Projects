/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_stack_push_back.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 22:15:02 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/07/16 22:15:26 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_lst_stack_push_back(size_t channel, \
	void *content, size_t content_size)
{
	t_list	*stack;
	t_list	*new;

	if (!(stack = ft_lst_stack_new_stack(channel)))
		return (0);
	if (!(new = (t_list *)ft_lstnew(content, content_size)))
		return (0);
	ft_lstadd_to_end((t_list **)(&(stack->content)), new);
	return (1);
}
