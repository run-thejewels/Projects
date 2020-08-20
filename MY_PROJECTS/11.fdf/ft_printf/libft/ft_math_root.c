/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math_root.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 21:17:49 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/01/04 21:35:54 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static float		rooter(float num, unsigned int root_index)
{
	float		num_temp;

	num_temp = num;
	while (root_index != 1)
	{
		num *= num_temp;
		root_index--;
	}
	return (num);
}

static int			sqrt_helper(int start, int nb, unsigned int root_index)
{
	float			sum;
	int				error_indicate;

	sum = 0;
	error_indicate = 0;
	if (start == 1)
	{
		if (rooter(start * 2, root_index) <= nb)
			start *= 2;
	}
	else
	{
		sum = 0.5;
		rooter(start + (sum * 2), root_index);
		while (rooter(start + (sum * 2), root_index) <= nb)
		{
			error_indicate = 1;
			sum *= 2;
		}
		if (error_indicate == 0)
			sum -= 0.5;
	}
	return (start + sum);
}

static float		root_helper(float num, unsigned int root_index)
{
	int				start;

	start = sqrt_helper(1, num, root_index);
	while (rooter(start, root_index) < num)
	{
		start = sqrt_helper(start, num, root_index);
		if (start == sqrt_helper(start, num, root_index) && start * start < num)
			break ;
	}
	return ((float)start);
}

static float		root_helper_2(float n, unsigned int r, float res, float c)
{
	int				index;

	index = 1;
	while (index < 10)
	{
		if (rooter(res + c, r) <= n)
			res += c;
		else
			break ;
		if (rooter(res, r) == n)
			index = 10;
		index++;
	}
	return (res);
}

float				ft_math_root(float num, unsigned int root_index)
{
	float			core;
	float			result;
	int				index;

	if ((!(root_index % 2) && num < 0) || !num || !root_index)
		return (0);
	result = root_helper(num, root_index);
	if (rooter(result, root_index) == num)
		return (result);
	core = 1.0;
	index = 6;
	while (index)
	{
		core /= 10;
		result = root_helper_2(num, root_index, result, core);
		index--;
	}
	return (result);
}
