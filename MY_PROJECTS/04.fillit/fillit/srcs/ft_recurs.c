/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recurs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfalia-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 16:07:02 by kfalia-f          #+#    #+#             */
/*   Updated: 2019/02/02 20:16:09 by kfalia-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		ft_clear(int **map, char **result, int fn)
{
	ft_clearspot(map[fn], result, 2);
	fn--;
	ft_clearspot(map[fn], result, 1);
	return (fn);
}

void	ft_recurs(int **map, char **result, int mapsize, int fn)
{
	while (map[fn][0] >= 0)
		if (ft_checkspot(map[fn], result, mapsize) == 1)
		{
			ft_touch(map[fn], result, fn);
			fn++;
		}
		else if ((ft_findeq(map, fn, fn)) == 1)
			continue ;
		else if (map[fn][10] + map[fn][4] < mapsize)
			map[fn][10] += 1;
		else if (map[fn][9] + map[fn][0] < mapsize)
		{
			map[fn][10] = 0;
			map[fn][9] = map[fn][9] + 1;
		}
		else if (fn > 0)
		{
			if (ft_qvad(map[fn]) == 0)
				if ((fn - ft_checkeq(map, fn, fn)) == 0)
					return ;
			fn = ft_clear(map, result, fn);
		}
		else
			return ;
	map[fn][0] = -2;
}
