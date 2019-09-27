/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajon-hol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 22:13:42 by ajon-hol          #+#    #+#             */
/*   Updated: 2018/10/09 00:21:54 by ajon-hol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

char	*ft_read_map(int fd)
{
	char	*map;
	char	*buf;
	int		ret;

	map = (char*)malloc(sizeof(char));
	map[0] = '\0';
	buf = (char*)malloc(sizeof(char) * (BUF_SIZE + 1));
	while ((ret = read(fd, buf, BUF_SIZE)))
	{
		buf[ret] = '\0';
		map = ft_map_concat(map, buf);
	}
	free(buf);
	close(fd);
	return (map);
}
