/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_concat.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajon-hol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 21:19:34 by ajon-hol          #+#    #+#             */
/*   Updated: 2018/10/10 16:31:51 by ajon-hol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

char	*ft_map_concat(char *map, char buf)
{
	char	*map_concat;
	int		i;
	int		j;

	map_concat = (char*)malloc(sizeof(char) * (ft_strlen(0, map, '\0') + 2));
	i = 0;
	j = 0;
	while (map[i] != '\0')
	{
		map_concat[j] = map[i];
		i++;
		j++;
	}
	free(map);
	map_concat[j] = buf;
	j++;
	map_concat[j] = '\0';
	return (map_concat);
}
