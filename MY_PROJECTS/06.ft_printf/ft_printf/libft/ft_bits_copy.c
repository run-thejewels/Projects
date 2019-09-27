/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bits_copy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 20:11:46 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/06/29 20:16:32 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_bits_copy_helper(void *src, void *dst, \
	size_t amount, size_t begin)
{
	size_t		index;
	size_t		result;

	index = 0;
	result = 0;
	while (result < amount)
	{
		ft_bits_write_bit(dst, index, ft_bits_read_bit(src, begin));
		index++;
		begin++;
		if (begin == 8)
		{
			begin = 0;
			src = ft_jump(src, 1);
		}
		if (index == 8)
		{
			index = 0;
			dst = ft_jump(dst, 1);
		}
		result++;
	}
	return (result / 8 + (result % 8) ? 1 : 0);
}

size_t			ft_bits_copy(void *src, void *dst, size_t amount, size_t begin)
{
	size_t		jump;

	if (!src || !amount || !dst)
		return (0);
	jump = 0;
	if (begin > 7)
	{
		jump = (begin) / 8;
		src = ft_jump(src, jump);
		begin -= jump * 8;
	}
	return (ft_bits_copy_helper(src, dst, amount, begin));
}
