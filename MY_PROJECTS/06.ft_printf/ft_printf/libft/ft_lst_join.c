/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_join.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 20:45:42 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/05/07 20:51:52 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lst_join(t_list *first, t_list *second)
{
	if (!first)
		return (second);
	if (!second)
		return (first);
	(ft_lst_get_end(first))->next = second;
	return (first);
}
