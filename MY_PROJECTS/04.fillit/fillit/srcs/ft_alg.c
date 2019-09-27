/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alg.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfalia-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 16:29:49 by kfalia-f          #+#    #+#             */
/*   Updated: 2019/02/02 21:02:25 by kfalia-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		ft_mapmin(int n)
{
	int k;

	k = 2;
	while (k * k < n * 4)
		k++;
	return (k);
}

void	ft_alg(int **map, int n)
{
	int		mapsize;
	char	**result;

	mapsize = ft_mapmin(n);
	result = ft_memalloc2(mapsize, mapsize);
	while (1)
	{
		ft_recurs(map, result, mapsize, 0);
		if (map[n][0] == -1)
		{
			ft_back(map);
			ft_mass2del(&result);
			mapsize++;
			result = ft_memalloc2(mapsize, mapsize);
		}
		else
			break ;
	}
	ft_mass2delint(&map);
	ft_output(result);
}
