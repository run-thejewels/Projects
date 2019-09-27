/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bits_shift_right.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 21:37:31 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/05/10 13:29:20 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_bits_shift_right(void *mem, size_t size_bytes, size_t shift_bits)
{
	size_t	index;

	if (!mem || !size_bytes || !shift_bits)
		return ;
	if ((shift_bits + 1) / 8 >= size_bytes)
	{
		ft_bzero(mem, size_bytes);
		return ;
	}
	index = 0;
	while (index <= (size_bytes * 8 - 1) - shift_bits)
	{
		ft_bits_write_bit(ft_jump(mem, ((index + \
		shift_bits + 1) / 8)), ((index + shift_bits) - ((((index + \
		shift_bits) + 1) / 8) * 8) - 1), \
		ft_bits_read_bit(ft_jump(mem, \
		((index + 1) / 8)), (index - (((index + 1) / 8) * 8) - 1)));
		index++;
	}
	ft_bits_filler(mem, 0, shift_bits, 0);
}
