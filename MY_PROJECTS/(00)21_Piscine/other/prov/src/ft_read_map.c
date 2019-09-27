/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajon-hol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 22:13:42 by ajon-hol          #+#    #+#             */
/*   Updated: 2018/10/10 19:48:21 by ajon-hol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

char	*ft_init_string(void)
{
	char *str;

	str = (char *)malloc(sizeof(char));
	*str = '\0';
	return (str);
}

char	**ft_read_map(int fd, t_mapdata *mapdata)
{
	char	buf;
	char	**map;
	int		i;
	int		ret;

	i = 0;
	map = (char **)malloc(sizeof(char*) * (mapdata->y));
	while (!(i == mapdata->y && (!(ret = read(fd, &buf, 1)) ||
								(buf == '\n' && fd == 0))))
	{
		map[i] = ft_init_string();
		while ((ret = read(fd, &buf, 1)))
		{
			if (map[i] && buf != '\n')
				map[i] = ft_map_concat(map[i], buf);
			if (buf == '\n')
				break ;
		}
		mapdata->x = ft_strlen(0, map[0], '\0');
		if (!ft_check_string(map[i], mapdata))
			return (NULL);
		i++;
	}
	close(fd);
	return (map);
}
