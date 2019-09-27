/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkspot.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfalia-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 21:05:06 by kfalia-f          #+#    #+#             */
/*   Updated: 2019/01/31 05:45:45 by kfalia-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		ft_checkspot(int *map, char **result, int mapsize)
{
	int		co;

	co = 0;
	while (co < 4)
	{
		if (((map[co] + map[9]) < mapsize)
				&& ((map[co + 4] + map[10]) < mapsize))
		{
			if (result[map[co] + map[9]][map[co + 4] + map[10]] == '.')
			{
				co++;
				continue ;
			}
			else
				return (0);
		}
		else
			return (0);
	}
	return (1);
}
