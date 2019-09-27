/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_mapdata.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajon-hol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 13:05:57 by ajon-hol          #+#    #+#             */
/*   Updated: 2018/10/10 16:36:14 by ajon-hol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

t_mapdata	*ft_create_mapdata(int y_data, char empty_data, char obstacle_data,
							char fill_data)
{
	t_mapdata *mapdata;

	mapdata = (t_mapdata *)malloc(sizeof(t_mapdata));
	mapdata->x = 0;
	mapdata->y = y_data;
	mapdata->empty = empty_data;
	mapdata->obstacle = obstacle_data;
	mapdata->fill = fill_data;
	return (mapdata);
}
