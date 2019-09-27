/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_unit_transfer.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 00:29:35 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/02/20 00:29:48 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lst_unit_transfer(t_list *lst)
{
	t_list	*new;

	if (!lst || !(new = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	new->content = lst->content;
	new->content_size = lst->content_size;
	new->next = NULL;
	return (new);
}
