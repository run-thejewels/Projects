/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_chain_len.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 00:23:12 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/02/20 00:23:27 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_lst_chain_len(t_list *begin)
{
	size_t	index;

	index = 0;
	while (begin)
	{
		index++;
		begin = begin->next;
	}
	return (index);
}
