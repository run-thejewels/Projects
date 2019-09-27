/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_map_data.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajon-hol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 13:05:57 by ajon-hol          #+#    #+#             */
/*   Updated: 2018/10/10 16:31:10 by ajon-hol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

t_mapdata	*ft_get_map_data(char *str)
{
	int res;

	res = 0;
	if (*str < '1' || *str >= '9')
		return (NULL);
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + *str - '0';
		str++;
	}
	if (*str == '\0' && res >= 1000)
		return (ft_create_mapdata(res / 1000, res % 1000 / 100 + '0',
								res % 100 / 10 + '0', res % 10 + '0'));
	else if (*(str + 3) == '\0' && *str != '\0' && *(str + 1) != '\0' &&
			*(str + 2) != '\0')
		return (ft_create_mapdata(res, *str, *(str + 1), *(str + 2)));
	return (NULL);
}
