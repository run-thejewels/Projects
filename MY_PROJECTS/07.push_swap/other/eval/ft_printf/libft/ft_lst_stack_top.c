/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_stack_top.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 23:38:00 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/04/22 23:41:52 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_lst_stack_top(size_t channel)
{
	t_list	*stack;

	if (!(stack = ft_lst_stack_new_stack(channel)))
		return (NULL);
	if (!(stack->content))
		return (NULL);
	return (((t_list *)(stack->content))->content);
}
