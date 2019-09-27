/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math_numlen_long_double.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 03:04:14 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/03/15 03:05:56 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	how_long_integer_part_in_tdld(long double num)
{
	size_t		count;

	if (num < 1.0)
		return (0);
	count = 1;
	if (num >= 1.0 && num < 10)
		return (count);
	while (num >= 10.0)
	{
		count++;
		num /= 10;
	}
	return (count);
}

static size_t	how_long_fractional_part_in_tdld(long double num)
{
	size_t		count;

	count = 0;
	if (num >= 1.0)
		num -= ft_math_rounding_down_l_double(num);
	while (num - ft_math_rounding_down_l_double(num))
	{
		count++;
		num *= 10;
	}
	return (count);
}

size_t			ft_math_numlen_long_double(long double num)
{
	size_t		result;

	if (!num)
		return (1);
	if (num == -0.0)
		return (1);
	result = 0;
	if (num < 0)
	{
		num *= -1;
		result++;
	}
	result += how_long_integer_part_in_tdld(num);
	result += how_long_fractional_part_in_tdld(num);
	return (result);
}
