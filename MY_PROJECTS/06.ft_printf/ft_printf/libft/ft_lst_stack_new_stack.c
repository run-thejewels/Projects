/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_stack_new_stack.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 21:44:36 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/04/22 23:11:52 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lst_stack_new_stack(size_t channel)
{
	t_list	**keeper;
	t_list	*stacks;
	t_list	*temp;

	keeper = ft_lst_stack_keep_stacks(0);
	if ((temp = ft_lstsearch_cs_replace(keeper, channel)))
		return (temp);
	stacks = *keeper;
	if (!(temp = ft_lstnew_no_copy(NULL, 0)))
		return (NULL);
	ft_lstadd_to_end(&stacks, temp);
	temp->content_size = channel;
	return (temp);
}
