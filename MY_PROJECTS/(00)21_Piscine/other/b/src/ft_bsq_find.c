/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bsq_find.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajon-hol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 10:12:12 by ajon-hol          #+#    #+#             */
/*   Updated: 2018/10/09 00:33:38 by ajon-hol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

t_frame		*ft_bsq_find(char **map, t_frame *current, t_frame *memory,
						t_mapdata *mapdata)
{
    while(current->x + current->size != mapdata->x &&
          current->y + current->size != mapdata->y)
    {
        if (ft_frame_check(map, current, mapdata->obstacle))
        {
            memory->x = current->x;
            memory->y = current->y;
            memory->size = current->size;
            if (current->x + current->size < mapdata->x &&
                current->y + current->size < mapdata->y)
                current->size++;
        }
        else if (current->x + current->size + 1 <= mapdata->x)
            current->x++;
        else if (current->y + current->size + 1 <= mapdata->y)
        {
            current->x = 0;
            current->y++;
        }
	}
	return (memory);
}
