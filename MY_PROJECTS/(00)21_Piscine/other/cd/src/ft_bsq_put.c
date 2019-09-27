/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bsq_put.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajon-hol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 10:12:12 by ajon-hol          #+#    #+#             */
/*   Updated: 2018/10/08 14:54:41 by ajon-hol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	ft_bsq_put(char **map, t_frame *memory, char fill)
{
	int	j;
	int	i;
	int	count_x;
	int	count_y;

	j = memory->x;
	i = memory->y;
	count_y = memory->size;
	while (count_y > 0)
	{
		count_x = memory->size;
		while (count_x > 0)
		{
			map[i][j] = fill;
			j++;
			count_x--;
		}
		count_y--;
		j = memory->x;
		i++;
	}
}
