/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math_rounding_down_float.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 19:05:59 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/03/15 04:25:38 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

float			ft_math_rounding_down_float(float num)
{
	long int	res_temp;
	float		result;

	res_temp = (long int)num;
	result = (float)res_temp;
	if (result >= 0 && result <= num)
		return (result);
	else if (result >= 0 && result > num)
		return (result - 1.0);
	else if (result < 0 && result >= num)
		return (result);
	return (result + 1.0);
}
