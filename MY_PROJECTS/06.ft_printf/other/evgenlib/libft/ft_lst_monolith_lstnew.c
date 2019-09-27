/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_monolith_lstnew.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 22:59:12 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/04/09 23:08:39 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lst_monolith_lstnew(void *content, \
	void *new_lst, size_t content_size)
{
	t_list	*new;

	new = (t_list	*)new_lst;
	new->content = content;
	if (!content_size)
	{
		new->content = NULL;
		new->content_size = 0;
	}
	else
		new->content_size = content_size;
	new->next = NULL;
	return (new);
}
