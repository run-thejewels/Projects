/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/25 15:20:53 by ahalmon-          #+#    #+#             */
/*   Updated: 2018/12/25 15:27:27 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *next_temp;
	t_list *temp;

	if (!*alst || !del)
		return ;
	next_temp = *alst;
	temp = *alst;
	while (next_temp)
	{
		next_temp = (*alst)->next;
		ft_lstdelone(&*alst, del);
		*alst = next_temp;
	}
	*alst = temp;
	*alst = NULL;
}
