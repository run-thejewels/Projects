/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bsq_find_and_print.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajon-hol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 12:30:46 by ajon-hol          #+#    #+#             */
/*   Updated: 2018/10/09 18:04:39 by ajon-hol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	ft_bsq_find_and_print(char **map, t_mapdata *mapdata)
{
	t_frame *memory;
	t_frame *current;

	memory = ft_create_frame(0, 0, 0);
	current = ft_create_frame(0, 0, 1);
	memory = ft_bsq_find(map, current, memory, mapdata);
	ft_map_print(map, memory, mapdata);
}
