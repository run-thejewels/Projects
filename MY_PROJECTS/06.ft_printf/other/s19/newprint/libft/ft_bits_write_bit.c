/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bits_write_bit.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 18:23:23 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/05/09 19:52:11 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				ft_bits_write_bit(void *byte, size_t num_bit, \
	unsigned char value)
{
	unsigned char	temp;

	if (!byte || value > 1 || num_bit > 7)
		return ;
	temp = *((unsigned char *)byte);
	if (value)
		temp |= (1 << num_bit);
	else
		temp &= ~(1 << num_bit);
	*((unsigned char *)byte) = temp;
}
