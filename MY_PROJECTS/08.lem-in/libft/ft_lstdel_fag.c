/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel_fag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsabre-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 12:04:24 by bsabre-c          #+#    #+#             */
/*   Updated: 2019/09/23 12:07:06 by bsabre-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel_fag(t_list **list)
{
	t_list	*tmp;
	t_list	*lst;

	if (!list || !(*list))
		return ;
	lst = *list;
	while (lst)
	{
		tmp = lst;
		lst = lst->next;
		free(tmp);
	}
	*list = NULL;
}
