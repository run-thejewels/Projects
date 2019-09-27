/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_concat.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajon-hol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 21:19:34 by ajon-hol          #+#    #+#             */
/*   Updated: 2018/10/09 00:25:15 by ajon-hol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

char	*ft_map_concat(char *map, char *buf)
{
	char	*map_concat;
	int		i;
	int		j;

	map_concat = (char*)malloc(sizeof(char) *
							(ft_strlen(map, '\0') + ft_strlen(buf, '\0') + 1));
	i = 0;
	j = 0;
	while (map[i] != '\0')
	{
		map_concat[j] = map[i];
		i++;
		j++;
	}
	free(map);
	i = 0;
	while (buf[i] != '\0')
	{
		map_concat[j] = buf[i];
		i++;
		j++;
	}
	map_concat[j] = '\0';
	return (map_concat);
}
