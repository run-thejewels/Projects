/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bits_reverse_bits_in_byte.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 19:31:02 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/05/09 19:51:30 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				ft_bits_reverse_bits_in_byte(void *byte)
{
	unsigned char	temp;
	size_t			index;

	if (!byte)
		return ;
	index = 0;
	while (index < 8)
	{
		ft_bits_write_bit(&temp, index, ft_bits_read_bit(byte, 7 - index));
		index++;
	}
	*((unsigned char *)byte) = temp;
}
