/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_frame_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajon-hol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 13:26:36 by ajon-hol          #+#    #+#             */
/*   Updated: 2018/10/09 00:28:40 by ajon-hol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int		ft_frame_check(char **map, t_frame *current, char obstacle)
{
	int		j;
	int		i;
	int		count_x;
	int		count_y;

	j = current->x;
	i = current->y;
	count_y = current->size;
	while (count_y > 0)
	{
		count_x = current->size;
		while (count_x > 0)
		{
			if (map[i][j] == obstacle)
				return (0);
			j++;
			count_x--;
		}
		count_y--;
		j = current->x;
		i++;
	}
	return (1);
}
