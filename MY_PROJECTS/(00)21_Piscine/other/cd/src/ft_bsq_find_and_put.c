/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bsq_find_and_put.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajon-hol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 12:30:46 by ajon-hol          #+#    #+#             */
/*   Updated: 2018/10/08 14:55:42 by ajon-hol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	ft_bsq_find_and_put(char **map, t_mapdata *mapdata)
{
	t_frame *memory;
	t_frame *current;

	memory = ft_create_frame(0, 0, 0);
	current = ft_create_frame(0, 0, 1);
	memory = ft_bsq_find(map, current, memory, mapdata);
	if (memory->size > 0)
		ft_bsq_put(map, memory, mapdata->fill);
}
