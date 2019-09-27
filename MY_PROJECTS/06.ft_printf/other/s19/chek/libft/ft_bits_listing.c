/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bits_listing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 20:18:31 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/06/29 20:18:33 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_bits_listing(void *mem, size_t num_bytes)
{
	size_t		index;
	size_t		index2;
	char		*temp;
	t_list		*lst;

	if (!mem || !num_bytes)
		return (NULL);
	index = 0;
	temp = (char *)mem;
	lst = NULL;
	while (index < num_bytes)
	{
		index2 = 0;
		while (index2 < 8)
		{
			if (ft_bits_read_bit(&temp[index], index2))
				ft_lstadd(&lst, ft_lstnew("1", 1));
			else
				ft_lstadd(&lst, ft_lstnew("0", 1));
			index2++;
		}
		index++;
	}
	return (ft_lst_strjoin_free_cs(ft_lst_turn(lst)));
}
