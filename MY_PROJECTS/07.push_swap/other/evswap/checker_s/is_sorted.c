/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 21:54:31 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/07/22 21:54:34 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../shared_s/push_swap.h"

int is_sorted(int *ints, size_t size)
{
	size_t index;

	index = 0;
	while (index < size)
	{
		if (index)
		{
			if (ints[index] < ints[index - 1])
				return (0);
		}
		index++;
	}
	return (1);
}
