/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_n_bytes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 18:14:45 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/04/06 18:54:03 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_swap_n_bytes(void *a, void *b, size_t n)
{
	size_t	index;

	if (!a || !b || !n)
		return ;
	index = 0;
	while (index != n)
	{
		ft_swap_byte(a + index, b + index);
		index++;
	}
}
