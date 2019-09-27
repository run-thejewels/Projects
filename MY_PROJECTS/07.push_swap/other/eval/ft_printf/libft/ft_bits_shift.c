/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bits_shift.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 13:19:36 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/05/10 13:25:40 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bits_shift(void *mem, size_t size_bytes, \
	size_t shift_bits, char *direction)
{
	if (direction && (!ft_strcmp(direction, "<<") || \
	!ft_strcmp(direction, "left")))
		ft_bits_shift_left(mem, size_bytes, shift_bits);
	else if (direction && (!ft_strcmp(direction, ">>") || \
	!ft_strcmp(direction, "right")))
		ft_bits_shift_right(mem, size_bytes, shift_bits);
}
