/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajon-hol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 12:45:27 by ajon-hol          #+#    #+#             */
/*   Updated: 2018/10/09 17:20:53 by kbethany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	main(int argc, char **argv)
{
	int			i;
	int			fd;
	char		*map;
	t_mapdata	*mapdata;

	i = 1;
	if (argc <= 1)
	{
		map = ft_read_map(0);
		mapdata = ft_get_map_data(map);
		ft_bsq_find_and_print(ft_transform(map, mapdata), mapdata);
		free(map);
	}
	else
	{
		while (i < argc)
		{
			fd = open(argv[i], O_RDONLY);
			map = ft_read_map(fd);
			mapdata = ft_get_map_data(map);e = 
			ft_bsq_find_and_print(ft_transform(map, mapdata), mapdata);
			free(map);
			i++;
		}
	}
	return (0);
}
