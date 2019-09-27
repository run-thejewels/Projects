/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_input.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfalia-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 16:33:36 by kfalia-f          #+#    #+#             */
/*   Updated: 2019/02/02 20:23:38 by kfalia-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	**ft_map(int i)
{
	char	**map;

	if ((map = (char **)malloc(sizeof(char *) * 129)) == NULL)
		ft_error(4);
	ft_bzero(map, sizeof(char *) * 129);
	while (i <= 129)
	{
		if ((map[i] = (char *)malloc(sizeof(char) * 5)) == NULL)
		{
			ft_mass2del(&map);
			ft_error(4);
		}
		ft_bzero(map[i], 5);
		i++;
	}
	return (map);
}

void	ft_input(int fd)
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
		if (map[i][j] == '\n' && (j == 4 || j == 0))
		{
			i++;
			j = 0;
		}
		else
			j++;
	}
	ft_valid(map);
}
