/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfalia-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 15:05:01 by kfalia-f          #+#    #+#             */
/*   Updated: 2019/01/24 16:43:56 by kfalia-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		ft_str(char **map)
{
	int		i;

	i = 0;
	while (map[i])
	{
		if (map[i][0] == '\0')
			break ;
		i++;
	}
	if ((i + 1) % 5 == 0)
		return (i);
	else
		ft_error(3);
	return (0);
}

void	ft_checkmap(char **map, int i, int k)
{
	int f;
	int o;
	int n;
	int j;

	f = 0;
	o = 0;
	n = 0;
	while (k < i + 4)
	{
		j = 0;
		while (map[k][j])
		{
			if (map[k][j] == '#')
				f++;
			if (map[k][j] == '.')
				o++;
			if (map[k][j] == '\n')
				n++;
			j++;
		}
		k++;
	}
	if (f != 4 || o != 12 || n != 4)
		ft_error(3);
}

void	ft_checktet(char **map, int i, int k, int str)
{
	int j;
	int neb;
	int	f;

	neb = 0;
	f = 0;
	while (k < i + 4)
	{
		j = -1;
		while (map[k][++j] != '\n')
		{
			if (map[k][j] == '#' && map[k][j + 1] == '#')
				neb++;
			if (k < str - 1)
			{
				if (map[k][j] == '#' && map[k + 1][j] == '#')
					neb++;
				if (map[k][j] == '#' && map[k + 1][j + 1] == '#')
					f = 1;
			}
		}
		k++;
	}
	if (neb != 3 && !(neb == 4 && f == 1))
		ft_error(3);
}

void	ft_checktetra(char **map, int str)
{
	int i;

	i = 0;
	while (i < str)
	{
		ft_checkmap(map, i, i);
		ft_checktet(map, i, i, str);
		i += 5;
	}
}

int		ft_valid(char **map)
{
	int		i;
	int		j;
	int		str;

	i = 0;
	j = 0;
	str = ft_str(map);
	if (((str + 1) / 5) > 26)
		ft_error(3);
	ft_checktetra(map, str);
	ft_newmap(map, (str + 1) / 5);
	return (1);
}
