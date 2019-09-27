/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mem_reverse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 20:33:15 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/04/30 20:44:22 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_mem_reverse(void *mem, size_t size, size_t amount)
{
	void	*end;

	if (!mem || !size || amount <= 1 || size * amount < size \
		|| size * amount < amount || size + 1 <= size)
		return ;
	end = ft_jump(mem, (amount - 1) * size);
	while (end > mem)
	{
		ft_swap_n_bytes(end, mem, size);
		mem = ft_jump(mem, size);
		end = ft_jump_pointer_to_n(end, (int)size * -1);
	}
}
