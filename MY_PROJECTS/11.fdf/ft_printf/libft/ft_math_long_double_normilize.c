/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math_long_double_normilize.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 04:54:38 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/03/17 22:44:50 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_math_long_double_normilize(long double *num)
{
	size_t	count;

	count = 1;
	if (*num >= 10.0)
	{
		while (*num >= 10.0)
		{
			count++;
			*num /= 10;
		}
	}
	return (count);
}
