/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_coord.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfalia-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 18:24:35 by kfalia-f          #+#    #+#             */
/*   Updated: 2019/01/29 17:54:46 by kfalia-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		**ft_arrey(char ***map, int n)
{
	int		i;
	int		**a;

	i = 0;
	if ((a = (int **)malloc(sizeof(*a) * (n + 1))) == NULL)
	{
		ft_mass2del(map);
		ft_error(4);
	}
	ft_bzero(a, sizeof(int *) * (n + 1));
	while (i <= n)
	{
		if ((a[i] = (int *)malloc(sizeof(**a) * 11)) == NULL)
		{
			ft_mass2delint(&a);
			ft_mass2del(map);
			ft_error(4);
		}
		ft_bzero(a[i], sizeof(int) * 11);
		i++;
	}
	return (a);
}

void	ft_zap(char **map, int **a, int i, int k)
{
	int j;
	int co;

	co = 0;
	while (k < i + 4)
	{
		j = 0;
		while (map[k][j])
		{
			if (map[k][j] == '#')
			{
				a[i / 5][co] = k - i;
				a[i / 5][co + 4] = j;
				co++;
			}
			j++;
		}
		k++;
	}
}

void	ft_coord(char **map, int n)
{
	int		**a;
	int		i;

	i = 0;
	a = ft_arrey(&map, n);
	while (i < (n * 5 - 1))
	{
		ft_zap(map, a, i, i);
		a[i / 5][8] = i / 5;
		a[i / 5][9] = 0;
		a[i / 5][10] = 0;
		i += 5;
	}
	a[n][0] = -1;
	ft_mass2del(&map);
	ft_alg(a, n);
}
