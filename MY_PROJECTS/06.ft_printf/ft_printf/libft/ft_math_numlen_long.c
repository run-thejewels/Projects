/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math_numlen_long.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 21:56:51 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/03/15 04:29:13 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_math_numlen_long(long int num)
{
	size_t	result;

	if (!num)
		return (1);
	result = 0;
	if (num < 0)
		result++;
	while (num)
	{
		num /= 10;
		result++;
	}
	return (result);
}
