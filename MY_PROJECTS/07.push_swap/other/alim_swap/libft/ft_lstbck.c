/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstbck.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rymuller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 15:37:54 by rymuller          #+#    #+#             */
/*   Updated: 2019/06/30 15:37:58 by rymuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstbck(t_list **alst, t_list *new)
{
	if (alst != NULL && *alst != NULL)
	{
		ft_lstbck(&(*alst)->next, new);
		if ((*alst)->next == NULL)
			(*alst)->next = new;
	}
}
