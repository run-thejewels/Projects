/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkeq.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfalia-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 01:26:09 by kfalia-f          #+#    #+#             */
/*   Updated: 2019/01/31 05:45:17 by kfalia-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		ft_checkeq(int **map, int fn, int fn1)
{
	int co;

	while (fn1 > 0)
	{
		co = 0;
		while (co < 8)
		{
			if (co < 4)
			{
				if (map[fn][co] != (map[fn1 - 1][co] - map[fn1 - 1][9]))
					return (fn - fn1);
			}
			else if (map[fn][co] != (map[fn1 - 1][co] - map[fn1 - 1][10]))
				return (fn - fn1);
			co++;
		}
		fn1--;
	}
	return (fn - fn1);
}
