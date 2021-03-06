/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bsq_find.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajon-hol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 10:12:12 by ajon-hol          #+#    #+#             */
/*   Updated: 2018/10/09 18:10:58 by ajon-hol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

t_frame		*ft_bsq_find(char **map, t_frame *current, t_frame *memory,
						t_mapdata *mapdata)
{
	while (1)
	{
		if (ft_frame_check(map, current, mapdata->obstacle))
		{
			memory = ft_create_frame(current->x, current->y, current->size);
			if (current->x + (current->size + 1) - 1 < mapdata->x &&
				current->y + (current->size + 1) - 1 < mapdata->y)
				current->size++;
			else
				break ;
			continue;
		}
		else if ((current->x + 1) + current->size - 1 < mapdata->x)
			current->x++;
		else if ((current->y + 1) + current->size - 1 < mapdata->y)
		{
			current->x = 0;
			current->y++;
		}
		else
			break ;
	}
	return (memory);
}
