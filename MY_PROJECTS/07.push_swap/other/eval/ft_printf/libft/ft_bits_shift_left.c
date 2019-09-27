/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bits_shift_left.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 13:14:28 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/05/10 13:18:46 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bits_shift_left(void *mem, size_t size_bytes, size_t shift_bits)
{
	ft_bits_reverse_memory(mem, size_bytes);
	ft_bits_shift_right(mem, size_bytes, shift_bits);
	ft_bits_reverse_memory(mem, size_bytes);
}
