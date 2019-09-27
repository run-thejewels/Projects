/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_transform.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajon-hol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 23:39:27 by ajon-hol          #+#    #+#             */
/*   Updated: 2018/10/09 00:18:29 by ajon-hol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

char	**ft_transform(char *map, t_mapdata *mapdata)
{
	char	**map2;
	int		j;
	int		i;
	int		k;

	k = 0;
	i = 0;
	while (map[k] != '\n')
		k++;
	k++;
	map2 = (char **)malloc(sizeof(char*) * mapdata->y);
	while (i < mapdata->y)
	{
		j = 0;
		map2[i] = (char *)malloc(sizeof(char) * mapdata->x);
		while (j < mapdata->x)
		{
			map2[i][j] = map[k];
			k++;
			j++;
		}
		map++;
		i++;
	}
	return (map2);
}
