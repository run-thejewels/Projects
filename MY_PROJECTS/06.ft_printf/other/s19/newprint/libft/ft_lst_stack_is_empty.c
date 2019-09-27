/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_stack_is_empty.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 21:41:54 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/04/22 23:12:52 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_lst_stack_is_empty(size_t channel)
{
	t_list	*stack;

	stack = ft_lst_stack_new_stack(channel);
	if (!stack || !stack->content)
		return (1);
	return (0);
}
