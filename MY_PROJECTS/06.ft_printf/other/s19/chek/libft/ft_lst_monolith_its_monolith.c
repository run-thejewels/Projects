/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_monolith_its_monolith.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 19:06:11 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/04/16 20:55:45 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_lst_monolith_its_monolith(t_list *lst)
{
	if (!lst)
		return (0);
	while (lst)
	{
		if (lst->next)
		{
			if (lst->next != \
				(t_list *)ft_jump(lst, sizeof(t_list)))
				return (0);
		}
		lst = lst->next;
	}
	return (1);
}
