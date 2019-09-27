/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajon-hol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 15:52:34 by ajon-hol          #+#    #+#             */
/*   Updated: 2018/10/09 01:16:15 by ajon-hol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	ft_map_print(char **map, t_frame *memory, t_mapdata *mapdata)
{
	int i;
	int j;

	i = 0;
	while (i < mapdata->y)
	{
		j = 0;
		while (j < mapdata->x)
		{
			if (i >= memory->y && i < (memory->y + memory->size) &&
				j >= memory->x && j < (memory->x + memory->size))
				write(1, &mapdata->fill, 1);
			else
				write(1, &map[i][j], 1);
			j++;
		}
		free(map[i]);
		write(1, "\n", 1);
		i++;
	}
}
