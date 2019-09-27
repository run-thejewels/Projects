/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfalia-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 14:13:17 by kfalia-f          #+#    #+#             */
/*   Updated: 2018/12/14 15:41:50 by kfalia-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*link;
	t_list	*temp;

	if (!alst || !del)
		return ;
	link = *alst;
	while (link != NULL)
	{
		temp = link->next;
		del(link, link->content_size);
		link = temp;
	}
	*alst = NULL;
}
