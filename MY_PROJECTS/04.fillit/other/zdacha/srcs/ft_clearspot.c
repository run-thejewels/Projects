/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clearspot.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfalia-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 21:14:40 by kfalia-f          #+#    #+#             */
/*   Updated: 2019/01/23 16:49:15 by kfalia-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_clearspot(int *map, char **result, int flag)
{
	int co;

	co = 0;
	while (co < 4)
	{
		if (flag == 2)
			break ;
		result[map[co]][map[co + 4]] = '.';
		if (map[co] >= map[9] && map[co + 4] >= map[10])
		{
			map[co] = map[co] - map[9];
			map[co + 4] = map[co + 4] - map[10];
		}
		co++;
	}
	if (flag == 1)
		map[10] += 1;
	else
	{
		map[10] = 0;
		map[9] = 0;
	}
}
