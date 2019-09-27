/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_unit_transfer_with_malloc.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 19:30:16 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/05/24 19:30:18 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lst_unit_transfer_with_malloc(t_list *lst)
{
	t_list *new;

	if (!lst)
		return (NULL);
	new = ft_lstnew(lst->content, lst->content_size);
	return (new);
}
