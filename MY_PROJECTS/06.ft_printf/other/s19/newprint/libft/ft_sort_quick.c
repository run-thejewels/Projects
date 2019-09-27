/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_quick.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 18:15:36 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/04/06 18:14:24 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*pivot_swap(void *v1, void *v2, void *v3)
{
	if (v1 == v2)
		return (v3);
	else if (v1 == v3)
		return (v2);
	else if (v2 == v3)
		return (v1);
	else
		return (v3);
}

static int	pivot_shift(void *v1, void *v2, size_t size)
{
	return ((v2 - v1) / size);
}

static void	quick_swaper(void **begin, void **end, void **pivot, size_t size)
{
	ft_swap_n_bytes(*begin, *end, size);
	*pivot = pivot_swap(*begin, *end, *pivot);
	*begin = ft_jump(*begin, size);
	*end = ft_jump_pointer_to_n(*end, (int)size * -1);
}

void		ft_sort_quick(void *a, size_t size, \
	size_t amount, int (*f)(void *, void *))
{
	void	*pivot;
	void	*begin;
	void	*end;

	if (!a || !f || amount <= 1 || !size)
		return ;
	pivot = ft_jump(a, (amount - 1) * size);
	begin = a;
	end = pivot;
	while (begin <= end)
	{
		while (f(begin, pivot) < 0)
			begin = ft_jump(begin, size);
		while (f(end, pivot) > 0)
			end = ft_jump_pointer_to_n(end, (int)size * -1);
		if (begin <= end)
			quick_swaper(&begin, &end, &pivot, size);
	}
	if (a < end)
		ft_sort_quick(a, size, pivot_shift(a, end, size) + 1, f);
	if (begin < ft_jump(a, (amount - 1) * size))
		ft_sort_quick(begin, size, amount - pivot_shift(a, begin, size), f);
}
