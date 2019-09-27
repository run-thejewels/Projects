/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bits_filler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 21:47:08 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/06/23 22:04:21 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_bits_filler(void *mem, size_t begin, \
	size_t amount, unsigned char value)
{
	size_t index;
	size_t jump;

	if (!mem || !amount || value > 1 || ~((size_t)0) - begin < amount)
		return ;
	if (begin > 7)
	{
		jump = begin / 8;
		mem = ft_jump(mem, jump);
		begin -= jump * 8;
	}
	index = 0;
	while (index < amount)
	{
		ft_bits_write_bit(mem, begin, value);
		begin++;
		if (begin == 8)
		{
			begin = 0;
			mem = ft_jump(mem, 1);
		}
		index++;
	}
}
