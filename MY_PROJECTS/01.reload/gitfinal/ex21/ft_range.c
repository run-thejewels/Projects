/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbethany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 17:04:45 by kbethany          #+#    #+#             */
/*   Updated: 2018/11/28 13:44:59 by kbethany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*ar;
	int	i;

	if (min > max || min == max)
		return (0);
	ar = (int*)malloc(sizeof(int) * (max - min));
	i = 0;
	while (min + i < max)
	{
		ar[i] = min + i;
		i++;
	}
	return (ar);
}
