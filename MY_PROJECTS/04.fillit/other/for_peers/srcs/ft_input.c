/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_input.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfalia-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 16:33:36 by kfalia-f          #+#    #+#             */
/*   Updated: 2019/01/29 17:56:25 by kfalia-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	**ft_map(int i)
{
	char	**map;

	if ((map = (char **)malloc(sizeof(*map) * 129)) == NULL)
		ft_error(4);
	ft_bzero(map, sizeof(char *) * 129);
	while (i <= 129)
	{
		if ((map[i] = (char *)malloc(sizeof(**map) * 5)) == NULL)
		{
			ft_mass2del(&map);
			ft_error(4);
		}
		ft_bzero(map[i], 5);
		i++;
	}
	return (map);
}

int		ft_input(int fd)
{
	int		i;
	int		j;
	int		ret;
	char	buff[2];
	char	**map;

	i = 0;
	j = 0;
	map = ft_map(i);
	while ((ret = read(fd, buff, 1)) > 0)
	{
		buff[ret] = '\0';
		map[i][j] = buff[0];
		if (i == 129)
			ft_error(3);
		if (map[i][j] == '\n' && (j == 4 || j == 0))
		{
			i++;
			j = 0;
		}
		else
			j++;
	}
	ft_valid(map);
	return (0);
}
