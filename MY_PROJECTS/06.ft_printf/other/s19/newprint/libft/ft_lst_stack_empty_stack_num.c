/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_stack_empty_stack_num.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 20:21:25 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/04/26 16:31:19 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_lst_stack_empty_stack_num(void)
{
	size_t	index;
	t_list	*stacks;

	index = 0;
	stacks = *(ft_lst_stack_keep_stacks(0));
	while (stacks)
	{
		if (stacks->content_size >= index)
		{
			if (!stacks->content)
				return (stacks->content_size);
			index = stacks->content_size;
		}
		stacks = stacks->next;
	}
	return (index + 1);
}
