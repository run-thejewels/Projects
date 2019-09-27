/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math_rounding_down_double.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 19:41:25 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/03/06 19:42:57 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long int		ft_math_rounding_down_double(double num)
{
	long long int	result;

	result = (long long int)num;
	if (result >= 0 && (double)result <= num)
		return (result);
	else if (result >= 0 && (double)result > num)
		return (result - 1);
	else if (result < 0 && (double)result >= num)
		return (result);
	return (result + 1);
}
