/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_turn.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 22:02:51 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/02/20 00:52:18 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lst_turn(t_list *begin)
{
	t_list	*new;
	t_list	*new_chain;
	t_list	*begin_temp;

	new_chain = NULL;
	while (begin)
	{
		new = ft_lst_unit_transfer(begin);
		begin_temp = begin->next;
		free(begin);
		begin = begin_temp;
		ft_lstadd(&new_chain, new);
	}
	return (new_chain);
}
