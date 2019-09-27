/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bits_reverse_memory.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 19:44:11 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/05/09 19:52:49 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bits_reverse_memory(void *memory, size_t mem_size)
{
	if (!memory || !mem_size)
		return ;
	ft_mem_reverse(memory, 1, mem_size);
	ft_bits_reverse_bits_in_bytes(memory, mem_size);
}
