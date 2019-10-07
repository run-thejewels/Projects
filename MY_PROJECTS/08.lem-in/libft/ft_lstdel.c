/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsabre-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 19:45:02 by bsabre-c          #+#    #+#             */
/*   Updated: 2018/12/05 18:22:01 by bsabre-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*n_lst;
	t_list	*c_lst;

	if (!alst || !del)
		return ;
	c_lst = *alst;
	while (c_lst)
	{
		n_lst = c_lst->next;
		del(c_lst->content, c_lst->content_size);
		free(c_lst);
		c_lst = n_lst;
	}
	*alst = NULL;
}
