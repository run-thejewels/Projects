/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_index.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 22:50:46 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/07/22 22:50:48 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../shared_s/push_swap.h"

size_t get_index(int *ints, size_t size, int num)
{
	size_t result;

	result = 0;
	while (result < size)
	{
		if (ints[result] == num)
			break ;
		result++;
	}
	return (result);
}
