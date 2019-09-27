/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel_complite.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/17 20:09:05 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/03/17 22:52:21 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		nuller_two_pointers_and_free_1(t_list **p1, t_list **p2)
{
	if (!*p1)
		return ;
	free(*p1);
	*p1 = NULL;
	*p2 = NULL;
}

void			ft_lstdel_complite(t_list **this, t_list **first_elem)
{
	t_list		*temp;

	if (!*this || *this == *first_elem)
	{
		nuller_two_pointers_and_free_1(this, first_elem);
		return ;
	}
	temp = *first_elem;
	while (temp && temp->next && temp->next != *this)
		temp = temp->next;
	if (temp && temp->next == *this)
	{
		if ((*this)->next)
		{
			temp->next = (*this)->next;
			free(*this);
			*this = NULL;
		}
		else
		{
			temp->next = NULL;
			free(*this);
			*this = NULL;
		}
	}
}
