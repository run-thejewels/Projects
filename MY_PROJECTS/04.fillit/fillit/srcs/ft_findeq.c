/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_findeq.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfalia-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 15:21:21 by kfalia-f          #+#    #+#             */
/*   Updated: 2019/02/02 20:57:53 by kfalia-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		ft_change(int **map, int fn, int fn1)
{
	if (map[fn][8] == fn)
	{
		map[fn][9] = map[fn1][9];
		map[fn][10] = map[fn1][10] + 1;
		map[fn][8] = map[fn1][8];
	}
	else
		return (2);
	return (1);
}

int		ft_findeq(int **map, int fn, int fn1)
{
	int co;

	if (fn == 0)
		return (0);
	fn1 -= 1;
	while (fn1 >= 0)
	{
		co = 0;
		while (co < 4)
		{
			if (map[fn1][co] - map[fn1][9] == map[fn][co]
					&& map[fn1][co + 4] - map[fn1][10] == map[fn][co + 4])
				co++;
			else
				break ;
		}
		if (co == 4)
			return (ft_change(map, fn, fn1));
		fn1--;
	}
	return (0);
}
