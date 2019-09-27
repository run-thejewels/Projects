/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_cut.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/28 23:51:47 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/04/28 23:59:48 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lst_cut(t_list **list, t_list **previous)
{
	if (previous && *previous)
		(*previous)->next = (*list)->next;
	else
		*previous = (*list)->next;
}
