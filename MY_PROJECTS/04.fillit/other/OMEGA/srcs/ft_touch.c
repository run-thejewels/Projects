/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_touch.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfalia-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 16:42:30 by kfalia-f          #+#    #+#             */
/*   Updated: 2019/01/30 19:16:08 by kbethany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_touch(int fn, int *map, char **result)
{
	int		co;

	co = 0;
	while (co < 4)
	{
		result[map[co] + map[9]][map[co + 4] + map[10]] = fn + 'A';
		map[co] = map[co] + map[9];
		map[co + 4] = map[co + 4] + map[10];
		co++;
	}
}
