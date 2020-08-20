/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_stack_pop.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 22:57:37 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/04/22 23:10:35 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_lst_stack_pop(size_t channel)
{
	t_list	*stack;
	t_list	*temp;
	void	*result;

	if (!(stack = ft_lst_stack_new_stack(channel)))
		return (NULL);
	if (!(stack->content))
		return (NULL);
	result = ((t_list *)(stack->content))->content;
	temp = ((t_list *)(stack->content))->next;
	free(stack->content);
	stack->content = temp;
	return (result);
}
