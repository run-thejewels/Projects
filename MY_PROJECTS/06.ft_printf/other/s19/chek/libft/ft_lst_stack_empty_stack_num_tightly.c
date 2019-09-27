/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_stack_empty_stack_num_tightly.c             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 16:18:12 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/04/26 16:23:02 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_lst_stack_empty_stack_num_tightly(void)
{
	size_t	index;
	t_list	*stack;

	index = 0;
	while (((stack = ft_lst_stack_new_stack(index))->content))
		index++;
	return (index);
}
