/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbethany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 17:04:45 by kbethany          #+#    #+#             */
/*   Updated: 2018/11/23 17:34:29 by kbethany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int *ft_range(int min, int max)
{
	int	*ar;
	int	i;

	ar = (int*)malloc(sizeof(int) * (max - min));
	i = 0;
	while (ar[i] < max - 1)
	{
		ar[i] = min + i;
		i++;
	}
	return ar;
}
	
