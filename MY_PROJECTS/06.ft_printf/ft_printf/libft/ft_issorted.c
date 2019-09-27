/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_issorted.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/12 21:52:00 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/05/13 18:28:29 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_issorted(void *array, size_t arr_size, size_t piece_size, \
	int (*f)(void *, void *))
{
	size_t	index;

	if (!array || !arr_size || !piece_size || !f)
		return (0);
	index = 0;
	while (index < arr_size - 1)
	{
		if (f(array, ft_jump(array, piece_size)) < 0)
			return (0);
		array = ft_jump(array, piece_size);
		index++;
	}
	return (1);
}
