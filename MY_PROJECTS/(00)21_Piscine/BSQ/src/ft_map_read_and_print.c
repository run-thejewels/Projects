/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_read_and_print.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajon-hol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 21:19:34 by ajon-hol          #+#    #+#             */
/*   Updated: 2018/10/10 19:22:42 by ajon-hol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	ft_map_read_and_print(int fd)
{
	char		*first_line;
	t_mapdata	*mapdata;
	char		**map;

	mapdata = NULL;
	if (fd != -1)
		if ((first_line = ft_get_first_line(fd)))
			if ((mapdata = ft_get_map_data(first_line)))
				if ((map = ft_read_map(fd, mapdata)))
				{
					ft_bsq_find_and_print(map, mapdata);
					return ;
				}
	ft_putstr("map error\n");
}
