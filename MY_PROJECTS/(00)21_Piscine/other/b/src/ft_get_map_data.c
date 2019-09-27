/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_map_data.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajon-hol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 23:13:58 by ajon-hol          #+#    #+#             */
/*   Updated: 2018/10/09 00:26:15 by ajon-hol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

t_mapdata	*ft_get_map_data(char *map)
{
	t_mapdata	*mapdata;
	int			rows;

	rows = 0;
	mapdata = (t_mapdata *)(malloc(sizeof(t_mapdata)));
	while (*map >= '0' && *map <= '9')
	{
		rows = rows * 10 + *map - '0';
		map++;
	}
	mapdata->y = rows;
	mapdata->empty = *map;
	map++;
	mapdata->obstacle = *map;
	map++;
	mapdata->fill = *map;
	map++;
	map++;
	mapdata->x = ft_strlen(map, '\n');
	return (mapdata);
}
