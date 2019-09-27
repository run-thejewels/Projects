/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_coord.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfalia-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 18:24:35 by kfalia-f          #+#    #+#             */
/*   Updated: 2019/01/26 20:13:26 by kfalia-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		**ft_arrey(int n)
{
	int		i;
	int		**a;

	i = 0;
	if ((a = malloc(sizeof(*a) * (n + 1))) == NULL)
		ft_error(4);
	while (i <= n)
	{
		if ((a[i] = (int *)malloc(sizeof(int) * 11)) == NULL)
			ft_error(4);
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
	a = ft_arrey(n);
	while (i < (n * 5 - 1))
	{
		ft_zap(map, a, i, i);
		a[i / 5][8] = i / 5;
		a[i / 5][9] = 0;
		a[i / 5][10] = 0;
		i += 5;
	}
	a[n][0] = -1;
	ft_mass2del(map);
	ft_alg(a, n);
}
