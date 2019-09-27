/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_get_end.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 11:43:11 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/04/16 20:54:03 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lst_get_end(t_list *lst)
{
	t_list	*temp;

	if (!lst)
		return (NULL);
	if (!lst->next)
		return (lst);
	temp = lst;
	while (lst->next)
		lst = lst->next;
	return (lst);
}
