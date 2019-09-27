/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bsq_find.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajon-hol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 10:12:12 by ajon-hol          #+#    #+#             */
/*   Updated: 2018/10/08 14:53:48 by ajon-hol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

t_frame	*ft_bsq_find(char **map, t_frame *current, t_frame *memory,
					t_mapdata *mapdata)
{
	if (ft_frame_check(map, current, mapdata->obstacle))
	{
		memory->x = current->x;
		memory->y = current->y;
		memory->size = current->size;
		current->size++;
		if (current->x + current->size <= mapdata->x &&
			current->y + current->size <= mapdata->y)
			return (ft_bsq_find(map, current, memory, mapdata));
	}
	if (!ft_frame_check(map, current, mapdata->obstacle))
	{
		if (current->x + 1 + current->size <= mapdata->x)
		{
			current->x++;
			return (ft_bsq_find(map, current, memory, mapdata));
		}
		else if (current->y + 1 + current->size <= mapdata->y)
		{
			current->x = 0;
			current->y++;
			return (ft_bsq_find(map, current, memory, mapdata));
		}
	}
	return (memory);
}
