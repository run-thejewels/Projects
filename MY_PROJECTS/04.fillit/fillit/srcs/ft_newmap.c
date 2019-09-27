/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_newmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfalia-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 16:24:33 by kfalia-f          #+#    #+#             */
/*   Updated: 2019/02/02 20:40:48 by kfalia-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		ft_sdvigup(char **map, int i, int k)
{
	int j;
	int flag;

	flag = 0;
	while (k < i + 4)
	{
		j = 0;
		while (map[k][j])
		{
			if (map[k][j] == '#')
				flag = 1;
			j++;
		}
		if (flag == 1)
			break ;
		k++;
	}
	return (k - i);
}

int		ft_sdvigleft(char **map, int i, int k)
{
	int j;
	int flag;

	flag = 0;
	j = 0;
	while (map[k][j] != '\n')
	{
		k = i;
		while (k < i + 4)
		{
			if (map[k][j] == '#')
				flag = 1;
			k++;
		}
		if (flag == 1)
			break ;
		j++;
	}
	return (j);
}

void	ft_sdvig(char **map, int k, int up, int left)
{
	int i;
	int j;

	i = k + 4;
	while (k < i)
	{
		j = 0;
		while (map[k][j])
		{
			if (map[k][j] == '#')
			{
				map[k][j] = '.';
				map[k - up][j - left] = '#';
			}
			j++;
		}
		k++;
	}
}

void	ft_newmap(char **map, int n)
{
	int i;
	int up;
	int left;

	i = 0;
	while (i < (n * 5) - 1)
	{
		up = ft_sdvigup(map, i, i);
		left = ft_sdvigleft(map, i, i);
		ft_sdvig(map, i, up, left);
		i += 5;
	}
	ft_coord(map, n);
}
