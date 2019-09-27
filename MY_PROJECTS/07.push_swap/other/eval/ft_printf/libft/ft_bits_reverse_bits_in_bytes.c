/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bits_reverse_bits_in_bytes.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 19:39:15 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/05/09 19:43:15 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bits_reverse_bits_in_bytes(void *byte, size_t num_bytes)
{
	if (!byte || !num_bytes)
		return ;
	while (num_bytes)
	{
		ft_bits_reverse_bits_in_byte(byte + num_bytes - 1);
		num_bytes--;
	}
}
