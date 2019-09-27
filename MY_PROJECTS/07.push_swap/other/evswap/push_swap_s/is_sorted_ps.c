/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted_ps.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 21:54:31 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/07/22 21:54:34 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../shared_s/push_swap.h"

int is_sorted_ps(int *ints, size_t size)
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

int is_sorted_shift_ps(int *ints, size_t size)
{
	size_t index;
	size_t flag;

	index = 0;
	flag = 0;
	if (is_sorted_ps(ints, size))
		return (1);
	if (ints[size - 1] > ints[0])
		return (0);
	while (index < size)
	{
		if (index)
		{
			if (ints[index] < ints[index - 1])
			{
				if (flag)
					return (0);
				flag++;
			}
		}
		index++;
	}
	return (1);
}

static int *resize_ps(int *ints, size_t size, int new, size_t new_index)
{
	int *result;

	if (!(result = (int *)malloc(sizeof(int) * (size + 1))))
		return (NULL);
	if (new_index == size)
	{
		ft_memcpy(result, ints, size * sizeof(int));
		ft_memcpy(ft_jump(result, size * sizeof(int)), &new, sizeof(int));
	}
	else if (!new_index)
	{
		ft_memcpy(result, &new, sizeof(int));
		ft_memcpy(ft_jump(result, sizeof(int)), ints, size * sizeof(int));
	}
	else
	{
		ft_memcpy(result, ints, new_index * sizeof(int));
		ft_memcpy(ft_jump(result, new_index * sizeof(int)), &new, sizeof(int));
		ft_memcpy(ft_jump(result, (new_index + 1) * sizeof(int)), \
		ft_jump(ints, new_index * sizeof(int)), \
		(size - new_index) * sizeof(int));
	}
	return (result);
}

size_t is_sorted_shift_in_mind_ps(int *ints, size_t size, int new)
{
	size_t index;
	int *temp;
	int result;

	index = 0;
	while (index <= size)
	{
		temp = resize_ps(ints, size, new, index);
		result = is_sorted_shift_ps(temp, size + 1);
		free(temp);
		if (result)
			return (index);
		index++;
	}
	return (index);
}
